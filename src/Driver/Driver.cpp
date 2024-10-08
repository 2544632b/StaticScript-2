#include <cstdlib>
#include <antlr4-runtime.h>
#include "StaticScriptLexer.h"
#include "StaticScriptParser.h"
#include "AST/ASTBuilder.h"
#include "Sema/ScopeScanner.h"
#include "Sema/ReferenceResolver.h"
#include "Sema/TypeChecker.h"
#include "Sema/SemanticValidator.h"
#include "CodeGen/IRGenerator.h"
#include "Optimization/Optimizer.h"
#include "Support/Alias.h"
#include "Support/LLVM.h"
#include "Support/Error.h"

int main(int argc, char **argv) {
    llvm::InitLLVM X(argc, argv);
    llvm::cl::getRegisteredOptions().clear();
    llvm::cl::OptionCategory generalOptsCat("General Options");
    llvm::cl::OptionCategory genericOptsCat("Generic Options");
    llvm::cl::opt<String> inputFilename(llvm::cl::Positional, llvm::cl::desc("<input file>"));
    llvm::cl::opt<String> outputFilename("o", llvm::cl::value_desc("output file"), llvm::cl::desc("Write output to <output file>"),
                                         llvm::cl::cat(generalOptsCat));
    llvm::cl::opt<bool> emitLLVM("emit-llvm", llvm::cl::desc("Generate the LLVM representation for input file"), llvm::cl::cat(generalOptsCat));
    llvm::cl::opt<bool> noLink("c", llvm::cl::desc("Generate the target object file"), llvm::cl::cat(generalOptsCat));
    llvm::cl::opt<String> libDir("L", llvm::cl::desc("Specify lib library directory"));
    llvm::cl::opt<bool> optLevelO0("O0", llvm::cl::desc("Optimization level 0. Similar to clang -O0"),
                                   llvm::cl::cat(generalOptsCat));
    llvm::cl::opt<bool> optLevelO1("O1", llvm::cl::desc("Optimization level 1. Similar to clang -O1"), llvm::cl::cat(generalOptsCat));
    llvm::cl::opt<bool> optLevelO2("O2", llvm::cl::init(true), llvm::cl::desc("Optimization level 2. Similar to clang -O2"),
                                   llvm::cl::cat(generalOptsCat));
    llvm::cl::opt<bool> optLevelOs("Os", llvm::cl::desc("Like -O2 with extra optimizations for size. Similar to clang -Os"),
                                   llvm::cl::cat(generalOptsCat));
    llvm::cl::opt<bool> optLevelOz("Oz", llvm::cl::desc("Like -Os but reduces code size further. Similar to clang -Oz"),
                                   llvm::cl::cat(generalOptsCat));
    llvm::cl::opt<bool> optLevelO3("O3", llvm::cl::desc("Optimization level 3. Similar to clang -O3"), llvm::cl::cat(generalOptsCat));
    llvm::cl::opt<bool> showHelp("help", llvm::cl::desc("Display available options"), llvm::cl::cat(genericOptsCat));
    llvm::cl::opt<bool> showHelpAlias("h", llvm::cl::desc("Alias for --help"), llvm::cl::cat(genericOptsCat));
    llvm::cl::opt<bool> showVersion("version", llvm::cl::desc("Display the version of this program"), llvm::cl::cat(genericOptsCat));
    llvm::cl::opt<bool> showVersionAlias("v", llvm::cl::desc("Alias for --version"), llvm::cl::cat(genericOptsCat));

    llvm::cl::ParseCommandLineOptions(argc, argv, "StaticScript Compiler\n");

    if (showHelp || showHelpAlias) {
        llvm::cl::PrintHelpMessage(false, true);
        return 0;
    }

    if (showVersion || showVersionAlias) {
        llvm::outs() << "StaticScript v" << PROJECT_VERSION << '\n';
        llvm::outs() << "\033[0;31m""CAUTION: This is a Alpha version! ""\033[0;31m\n";
        return 0;
    }

    if (inputFilename.empty()) {
        llvm::cl::PrintHelpMessage(false, true);
        return 0;
    }

    llvm::StringRef inputBasename = llvm::sys::path::stem(inputFilename);

    String outputIRFilename;
    String outputObjFilename;
    String outputExeFilename;

    if (outputFilename.empty()) {
        outputIRFilename = llvm::formatv("{0}-ir.ll", inputBasename);
        outputObjFilename = llvm::formatv("{0}-out.o", inputBasename);
        outputExeFilename = llvm::formatv("{0}-out.out", inputBasename);
        // For windows, output is a PE (.exe)
    } else {
        outputIRFilename = outputObjFilename = outputExeFilename = outputFilename;
    }

    unsigned optLevel = 0;
    unsigned sizeLevel = 0;

    if (optLevelO3) {
        optLevel = 3;
    } else if (optLevelOz) {
        optLevel = 2;
        sizeLevel = 2;
    } else if (optLevelOs) {
        optLevel = 2;
        sizeLevel = 1;
    } else if (optLevelO1) {
        optLevel = 1;
    } else if (optLevelO0) {
        optLevel = 0;
    } else {
        optLevel = 2;
    }

    if (!llvm::sys::fs::exists(inputFilename)) {
        reportDriverError("Not found input file");
    }
    std::ifstream fin(inputFilename.data());
    reportOnDriverError(!fin, "Open input file failed");

    antlr4::ANTLRInputStream inputStream(fin);
    StaticScriptLexer lexer(&inputStream);
    antlr4::CommonTokenStream tokenStream(&lexer);
    tokenStream.fill();
    StaticScriptParser parser(&tokenStream);
    antlr4::tree::ParseTree *tree = parser.module();
    ASTBuilder builder(inputFilename.data());
    SharedPtr<ModuleNode> module = builder.visit(tree);
    // 语义分析: 1. 作用域扫描
    SharedPtr<ScopeScanner> scanner = makeShared<ScopeScanner>();
    scanner->resolve(module);
    // 语义分析: 2. 引用消解
    SharedPtr<ReferenceResolver> resolver = makeShared<ReferenceResolver>();
    resolver->resolve(module);
    // 语义分析: 3. 类型检查
    SharedPtr<TypeChecker> checker = makeShared<TypeChecker>();
    checker->resolve(module);
    // 语义分析: 4. 正确性检查
    SharedPtr<SemanticValidator> validator = makeShared<SemanticValidator>();
    validator->resolve(module);
    // 中间代码生成
    SharedPtr<IRGenerator> generator = makeShared<IRGenerator>();
    generator->resolve(module, libDir);

    LLVMModule &llvmModule = generator->getLLVMModule();

    // 初始化LLVM相关
    initLLVMTarget();
    initLLVMPasses();
    initLLVMCodeGen();

    // 设置target triple
    llvmModule.setTargetTriple(getTargetTriple());

    // 优化
    SharedPtr<Optimizer> optimizer = makeShared<Optimizer>(llvmModule, optLevel, sizeLevel);
    optimizer->optimize();

    llvm::TargetMachine *targetMachine = getTargetMachine(optLevel);

    // 设置data layout
    llvmModule.setDataLayout(targetMachine->createDataLayout());


    std::error_code ec;
    llvm::raw_fd_ostream dest(emitLLVM ? outputIRFilename : outputObjFilename, ec, llvm::sys::fs::OF_None);
    reportOnDriverError(bool(ec), "Could not create file: " + ec.message());

    if (emitLLVM) {
        dest << llvmModule;
    } else {
        llvm::legacy::PassManager pass;
        auto fileType = llvm::CGFT_ObjectFile;
        if (targetMachine->addPassesToEmitFile(pass, dest, nullptr, fileType)) {
            reportDriverError("TargetMachine can't emit a object file");
        }
        pass.run(llvmModule);
    }
    dest.flush();
    dest.close();
    fin.close();

    // Linking, using clang
    if (!emitLLVM && !noLink) {
        String linkCmd = llvm::formatv("clang++ {0} -lm -L/usr/local/Cellar/curl/8.8.0/lib -L/Users/chan/Desktop/libuv-1.x/lib -lcurl -luv -o {1}", outputObjFilename, outputExeFilename);
        system(linkCmd.data());
        if (outputFilename.empty()) {
            String rmCmd = llvm::formatv("rm -f {0}", outputObjFilename);
            // WINDOWS CMDs
            // String rmCmd = llvm::formatv("del /Y {0}", outputObjectFilename);
            system(rmCmd.data());
        }
    }
    return 0;
}