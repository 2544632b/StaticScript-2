#include "CodeGen/Builtin.h"

void Builtin::initialize(LLVMModule &module, LLVMContext &context, const llvm::Twine &libDirArg) {
    llvm::SmallString<256> libPath;
    if (!libDirArg.str().empty()) {
        libDirArg.toVector(libPath);
        if (!llvm::sys::path::is_absolute(libPath)) {
            if (llvm::sys::fs::make_absolute(libPath)) {
                reportLinkError("Parse the specified library directory failed");
            }
        }
        if (!llvm::sys::fs::exists(libPath)) {
            reportLinkError("The specified library directory does not exist");
        }
        if (!llvm::sys::fs::is_directory(libPath)) {
            reportLinkError("The specified library directory is not a directory");
        }
        libDir = libPath.str();
    } else {
        // 在当前执行目录下搜索lib目录
        llvm::sys::fs::current_path(libPath);
        llvm::sys::path::append(libPath, "lib");
        if (llvm::sys::fs::exists(libPath) && llvm::sys::fs::is_directory(libPath)) {
            libDir = libPath.str();
        }
    }

    if (!llvm::sys::fs::exists(libDir)) {
        reportLinkError("The library directory '" + libDir + "'does not exist");
    }

    BuiltinError::linkModule(module, context);
    BuiltinString::linkModule(module, context);
    BuiltinArray::linkModule(module, context);
    BuiltinIO::linkModule(module, context);
    BuiltinInput::linkModule(module, context);
    BuiltinMath::linkModule(module, context);
    BuiltinCurl::linkModule(module, context);
    BuiltinSocket::linkModule(module, context);
    BuiltinLoop::linkModule(module, context);

    BuiltinError::getTypeAndFunction(module);
    BuiltinString::getTypeAndFunction(module);
    BuiltinArray::getTypeAndFunction(module);
    BuiltinIO::getTypeAndFunction(module);
    BuiltinInput::getTypeAndFunction(module);
    BuiltinMath::getTypeAndFunction(module);
    BuiltinCurl::getTypeAndFunction(module);
    BuiltinSocket::getTypeAndFunction(module);
    BuiltinLoop::getTypeAndFunction(module);
}

#define BUILTIN_LINK_MODULE(moduleName) \
    llvm::SMDiagnostic error; \
    String bitcodeFilename = Builtin::libDir + "/lib_"#moduleName".bc"; \
    bool bitcodeExist = llvm::sys::fs::exists(bitcodeFilename); \
    reportOnLinkError(!bitcodeExist, "Not found " + bitcodeFilename); \
    std::unique_ptr<LLVMModule> bitcodeModule = llvm::parseIRFile(bitcodeFilename, error, context); \
    reportOnLinkError(!bitcodeModule, "Parse bitcode file of the "#moduleName" module failed"); \
    bool linkFailed = llvm::Linker::linkModules(module, std::move(bitcodeModule)); \
    reportOnLinkError(linkFailed, "Link "#moduleName" module failed");

void BuiltinError::linkModule(LLVMModule &module, LLVMContext &context) {
    BUILTIN_LINK_MODULE(error)
}

void BuiltinError::getTypeAndFunction(LLVMModule &module) {
    llvm::StructType *errStructType = llvm::StructType::getTypeByName(module.getContext(), "struct._error");
    type = errStructType->getPointerTo();
    exitIfErrorFunc = module.getFunction("ss_exit_if_error");
    assertFunc = module.getFunction("_assert");
}

void BuiltinString::linkModule(LLVMModule &module, LLVMContext &context) {
    BUILTIN_LINK_MODULE(string)
}

void BuiltinString::getTypeAndFunction(LLVMModule &module) {
    llvm::StructType *strStructType = llvm::StructType::getTypeByName(module.getContext(), "struct._string");
    type = strStructType->getPointerTo();
    createFunc = module.getFunction("_string_create");
    deleteFunc = module.getFunction("_string_delete");
    getSizeFunc = module.getFunction("_string_get_size");
    stringSizeFunc = module.getFunction("string_size");
    concatFunc = module.getFunction("_string_concat");
    appendFunc = module.getFunction("_string_append");
    prependFunc = module.getFunction("_string_prepend");
    sliceFunc = module.getFunction("_string_slice");
    getStringCharacterFunc = module.getFunction("_string_get_string_character");
    equalsFunc = module.getFunction("_string_equals");
    indexOfFunc = module.getFunction("_string_index_of");
    trimLeftFunc = module.getFunction("_string_trim_left");
    trimRightFunc = module.getFunction("_string_trim_right");
    trimFunc = module.getFunction("_string_trim");
}

void BuiltinArray::linkModule(LLVMModule &module, LLVMContext &context) {
    BUILTIN_LINK_MODULE(array)
}

void BuiltinArray::getTypeAndFunction(LLVMModule &module) {
    llvm::StructType *arrStructType = llvm::StructType::getTypeByName(module.getContext(), "struct._array");
    type = arrStructType->getPointerTo();
    createIntegerArrayFunc = module.getFunction("_array_create_integer_array");
    createFloatArrayFunc = module.getFunction("_array_create_float_array");
    createBooleanArrayFunc = module.getFunction("_array_create_boolean_array");
    createStringArrayFunc = module.getFunction("_array_create_string_array");
    createArrayArrayFunc = module.getFunction("_array_create_array_array");
    createIntegerArrayWithLiteralFunc = module.getFunction("_array_create_integer_array_with_literal");
    createFloatArrayWithLiteralFunc = module.getFunction("_array_create_float_array_with_literal");
    createBooleanArrayWithLiteralFunc = module.getFunction("_array_create_boolean_array_with_literal");
    createStringArrayWithLiteralFunc = module.getFunction("_array_create_string_array_with_literal");
    createArrayArrayWithLiteralFunc = module.getFunction("_array_create_array_array_with_literal");
    
    deleteFunc = module.getFunction("_array_delete");
    getSizeFunc = module.getFunction("_array_get_size");
    isNDArrayFunc = module.getFunction("_array_is_nd_array");
    isFloatArrayFunc = module.getFunction("_array_is_float_array");

    /*
    pushIntegerFunc = module.getFunction("_array_push_integer");
    pushFloatFunc = module.getFunction("_array_push_float");
    pushBooleanFunc = module.getFunction("_array_push_boolean");
    pushStringFunc = module.getFunction("_array_push_string");
    pushArrayFunc = module.getFunction("_array_push_array");
    */
    
    pushBackIntegerFunc = module.getFunction("push_back_integer");
    pushBackFloatFunc = module.getFunction("push_back_float");
    pushBackStringFunc = module.getFunction("push_back_string");

    /*
    popIntegerFunc = module.getFunction("_array_pop_integer");
    popFloatFunc = module.getFunction("_array_pop_float");
    popBooleanFunc = module.getFunction("_array_pop_boolean");
    popStringFunc = module.getFunction("_array_pop_string");
    popArrayFunc = module.getFunction("_array_pop_array");
    */

    getIntegerFunc = module.getFunction("_array_get_integer");
    getFloatFunc = module.getFunction("_array_get_float");
    getBooleanFunc = module.getFunction("_array_get_boolean");
    getStringFunc = module.getFunction("_array_get_string");
    getArrayFunc = module.getFunction("_array_get_array");
    
    setIntegerFunc = module.getFunction("_array_set_integer");
    setFloatFunc = module.getFunction("_array_set_float");
    setBooleanFunc = module.getFunction("_array_set_boolean");
    setStringFunc = module.getFunction("_array_set_string");
    setArrayFunc = module.getFunction("_array_set_array");

    sliceFunc = module.getFunction("_array_slice");
    arrayLengthFunc = module.getFunction("array_length");
    stringToArrayFunc = module.getFunction("string_to_array");
}

void BuiltinIO::linkModule(LLVMModule &module, LLVMContext &context) {
    BUILTIN_LINK_MODULE(io)
}

void BuiltinIO::getTypeAndFunction(LLVMModule &module) {
    integer2stringFunc = module.getFunction("integer2string");
    integer2asciiFunc = module.getFunction("integer2ascii");
    string2integerFunc = module.getFunction("string2integer");
    float2stringFunc = module.getFunction("float2string");
    string2floatFunc = module.getFunction("string2float");
    printIntegerFunc = module.getFunction("print_number");
    printlnIntegerFunc = module.getFunction("print_number_ln");
    printFloatFunc = module.getFunction("print_float");
    printlnFloatFunc = module.getFunction("print_float_ln");
    printStringFunc = module.getFunction("print_string");
    printlnStringFunc = module.getFunction("print_string_ln");
    printlnFunc = module.getFunction("print_ln");
}

void BuiltinInput::linkModule(LLVMModule &module, LLVMContext &context) {
    BUILTIN_LINK_MODULE(input)
}

void BuiltinInput::getTypeAndFunction(LLVMModule &module) {
    getStringFunc = module.getFunction("get_string");
}

void BuiltinMath::linkModule(LLVMModule &module, LLVMContext &context) {
    BUILTIN_LINK_MODULE(math)
}

void BuiltinMath::getTypeAndFunction(LLVMModule &module) {
    logFunc = module.getFunction("_log");
    log10Func = module.getFunction("_log10");
    powFunc = module.getFunction("_pow");
    sqrtFunc = module.getFunction("_sqrt");
    sinFunc = module.getFunction("_sin");
    cosFunc = module.getFunction("_cos");
    tanFunc = module.getFunction("_tan");
    ceilFunc = module.getFunction("_ceil");
    floorFunc = module.getFunction("_floor");
}

void BuiltinCurl::linkModule(LLVMModule &module, LLVMContext &context) {
    BUILTIN_LINK_MODULE(curl)
}

void BuiltinCurl::getTypeAndFunction(LLVMModule &module) {
    getCurlVersionFunc = module.getFunction("get_curl_version");
    requestGetRawFunc = module.getFunction("CurlRequestGetRaw");
}

void BuiltinSocket::linkModule(LLVMModule &module, LLVMContext &context) {
    BUILTIN_LINK_MODULE(socket)
}

void BuiltinSocket::getTypeAndFunction(LLVMModule &module) {
    llvm::StructType* socketStructType = llvm::StructType::getTypeByName(module.getContext(), "struct._socket");
    type = socketStructType->getPointerTo();
    createSocketFunc = module.getFunction("CreateSocket");
    setSocketMessageFunc = module.getFunction("SetSocketMessage");
    listenFunc = module.getFunction("Listen");
}

void BuiltinLoop::linkModule(LLVMModule &module, LLVMContext &context) {
    BUILTIN_LINK_MODULE(loop)
}

void BuiltinLoop::getTypeAndFunction(LLVMModule &module) {
    defaultLoopFunc = module.getFunction("DefaultLoop");
    loopSetupFunc = module.getFunction("LoopSetup");
}

