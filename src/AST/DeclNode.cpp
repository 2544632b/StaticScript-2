#include <utility>
#include "AST/DeclNode.h"
#include "Sema/ASTVisitor.h"

VarDeclNode::VarDeclNode() : modifier(VarModifier::Let) {}

VarDeclNode::VarDeclNode(
        VarModifier modifier,
        const SharedPtr<Type> &type
) : modifier(modifier), type(type) {}

VarDeclNode::VarDeclNode(
        VarModifier modifier,
        String name,
        const SharedPtr<Type> &type
) : modifier(modifier), name(std::move(name)), type(type) {}

// MultiType begin
/*
VarDeclNode::VarDeclNode(
        VarModifier modifier,
        String name,
        const std::vector<SharedPtr<Type>> &multiType
) : modifier(modifier), name(std::move(name)), multiType(multiType) {}
*/
// MultiType end

VarDeclNode::VarDeclNode(VarModifier modifier,
                         String name,
                         const SharedPtr<Type> &type,
                         const SharedPtr<ExprNode> &initVal
) : modifier(modifier), name(std::move(name)), type(type), initVal(initVal) {}

void VarDeclNode::accept(const SharedPtr<ASTVisitor> &visitor) {
    visitor->visit(staticPtrCast<VarDeclNode>(shared_from_this()));
}

void VarDeclNode::bindChildrenInversely() {
    auto self = shared_from_this();
    if (initVal) {
        initVal->parent = self;
    }
}

bool VarDeclNode::isConstant() const {
    return modifier == VarModifier::Const;
}

ParmVarDeclNode::ParmVarDeclNode(
        const SharedPtr<Type> &type
) : VarDeclNode(VarModifier::Param, type) {}

ParmVarDeclNode::ParmVarDeclNode(
        const String &name,
        const SharedPtr<Type> &type
) : VarDeclNode(VarModifier::Param, name, type) {}

void ParmVarDeclNode::accept(const SharedPtr<ASTVisitor> &visitor) {
    visitor->visit(staticPtrCast<ParmVarDeclNode>(shared_from_this()));
}

SharedPtrMap<String, FunctionDeclNode> FunctionDeclNode::getBuiltinFunctions() {
    SharedPtr<ArrayType> arrayType = makeShared<ArrayType>();
    SharedPtr<ArrayType> stringArrayType = makeShared<ArrayType>(BasicType::STRING_TYPE);
    SharedPtr<SocketType> socketType = makeShared<SocketType>();
    
    SharedPtrMap<String, FunctionDeclNode> functions;
    SharedPtr<ParmVarDeclNode> booleanArg = makeShared<ParmVarDeclNode>(BasicType::BOOLEAN_TYPE);
    SharedPtr<ParmVarDeclNode> integerArg = makeShared<ParmVarDeclNode>(BasicType::INTEGER_TYPE);
    SharedPtr<ParmVarDeclNode> floatArg = makeShared<ParmVarDeclNode>(BasicType::FLOAT_TYPE);
    SharedPtr<ParmVarDeclNode> strArg = makeShared<ParmVarDeclNode>(BasicType::STRING_TYPE);
    SharedPtr<ParmVarDeclNode> arrArg = makeShared<ParmVarDeclNode>(arrayType);
    SharedPtr<ParmVarDeclNode> sockArg = makeShared<ParmVarDeclNode>(socketType);

    SharedPtrVector<ParmVarDeclNode> booleanArgs{booleanArg};
    SharedPtrVector<ParmVarDeclNode> integerArgs{integerArg};
    SharedPtrVector<ParmVarDeclNode> floatArgs{floatArg};
    SharedPtrVector<ParmVarDeclNode> strArgs{strArg};
    SharedPtrVector<ParmVarDeclNode> arrArgs{arrArg};
    SharedPtrVector<ParmVarDeclNode> dFloatArgs{floatArg, floatArg};
    SharedPtrVector<ParmVarDeclNode> arrIntArgs{arrArg, integerArg};
    SharedPtrVector<ParmVarDeclNode> arrFloatArgs{arrArg, floatArg};
    SharedPtrVector<ParmVarDeclNode> arrStrArgs{arrArg, strArg};
    SharedPtrVector<ParmVarDeclNode> sockArgs{sockArg};
    SharedPtrVector<ParmVarDeclNode> listenSockArgs{sockArg, strArg, integerArg};
    SharedPtrVector<ParmVarDeclNode> writeSockStrArgs{sockArg, strArg};

    functions["integer2string"] = makeShared<FunctionDeclNode>("integer2string", integerArgs, BasicType::STRING_TYPE);
    functions["integer2ascii"] = makeShared<FunctionDeclNode>("integer2ascii", integerArgs, BasicType::STRING_TYPE);
    functions["string2integer"] = makeShared<FunctionDeclNode>("string2integer", strArgs, BasicType::INTEGER_TYPE);
    functions["float2string"] = makeShared<FunctionDeclNode>("float2string", floatArgs, BasicType::STRING_TYPE);
    functions["string2float"] = makeShared<FunctionDeclNode>("string2float", strArgs, BasicType::FLOAT_TYPE);
    functions["print_number"] = makeShared<FunctionDeclNode>("print_number", integerArgs);
    functions["print_number_ln"] = makeShared<FunctionDeclNode>("print_number_ln", integerArgs);
    functions["print_float"] = makeShared<FunctionDeclNode>("print_float", floatArgs);
    functions["print_float_ln"] = makeShared<FunctionDeclNode>("print_float_ln", floatArgs);
    functions["print_string"] = makeShared<FunctionDeclNode>("print_string", strArgs);
    functions["print_string_ln"] = makeShared<FunctionDeclNode>("print_string_ln", strArgs);
    functions["print_ln"] = makeShared<FunctionDeclNode>("print_ln");
    functions["get_string"] = makeShared<FunctionDeclNode>("get_string", BasicType::STRING_TYPE);
    functions["_assert"] = makeShared<FunctionDeclNode>("_assert", booleanArgs);

    functions["_log"] = makeShared<FunctionDeclNode>("_log", floatArgs, BasicType::FLOAT_TYPE);
    functions["_log10"] = makeShared<FunctionDeclNode>("_log10", floatArgs, BasicType::FLOAT_TYPE);
    functions["_pow"] = makeShared<FunctionDeclNode>("_pow", dFloatArgs, BasicType::FLOAT_TYPE);
    functions["_sqrt"] = makeShared<FunctionDeclNode>("_sqrt", dFloatArgs, BasicType::FLOAT_TYPE);
    functions["_sin"] = makeShared<FunctionDeclNode>("_sin", floatArgs, BasicType::FLOAT_TYPE);
    functions["_cos"] = makeShared<FunctionDeclNode>("_cos", floatArgs, BasicType::FLOAT_TYPE);
    functions["_tan"] = makeShared<FunctionDeclNode>("_tan", floatArgs, BasicType::FLOAT_TYPE);
    functions["_ceil"] = makeShared<FunctionDeclNode>("_ceil", floatArgs, BasicType::INTEGER_TYPE);
    functions["_floor"] = makeShared<FunctionDeclNode>("_floor", floatArgs, BasicType::INTEGER_TYPE);

    functions["string_size"] = makeShared<FunctionDeclNode>("string_size", strArgs, BasicType::INTEGER_TYPE);
    functions["string_to_array"] = makeShared<FunctionDeclNode>("string_to_array", strArgs, stringArrayType);
    functions["array_length"] = makeShared<FunctionDeclNode>("array_length", arrArgs, BasicType::INTEGER_TYPE);
    
    functions["push_back_integer"] = makeShared<FunctionDeclNode>("push_back_integer", arrIntArgs);
    functions["push_back_float"] = makeShared<FunctionDeclNode>("push_back_float", arrFloatArgs);
    functions["push_back_string"] = makeShared<FunctionDeclNode>("push_back_string", arrStrArgs);

    functions["get_curl_version"] = makeShared<FunctionDeclNode>("get_curl_version", BasicType::STRING_TYPE);
    functions["get_uname"] = makeShared<FunctionDeclNode>("get_uname", BasicType::STRING_TYPE);
    
    functions["CurlRequestGetRaw"] = makeShared<FunctionDeclNode>("CurlRequestGetRaw", strArgs, BasicType::STRING_TYPE);

    functions["CreateSocket"] = makeShared<FunctionDeclNode>("CreateSocket", socketType);
    functions["SetSocketMessage"] = makeShared<FunctionDeclNode>("SetSocketMessage", writeSockStrArgs);
    functions["Listen"] = makeShared<FunctionDeclNode>("Listen", listenSockArgs);

    return functions;
}

FunctionDeclNode::FunctionDeclNode(
    String name
) : name(std::move(name)) {}

FunctionDeclNode::FunctionDeclNode(
        String name,
        const SharedPtrVector<ParmVarDeclNode> &params
) : name(std::move(name)),
    params(params) {}

FunctionDeclNode::FunctionDeclNode(
        String name,
        const SharedPtr<Type> &returnType
) : name(std::move(name)),
    returnType(returnType) {}

FunctionDeclNode::FunctionDeclNode(
        String name,
        const SharedPtrVector<ParmVarDeclNode> &params,
        const SharedPtr<Type> &returnType
) : name(std::move(name)),
    params(params),
    returnType(returnType) {}

FunctionDeclNode::FunctionDeclNode(
        String name,
        const SharedPtrVector<ParmVarDeclNode> &params,
        const SharedPtr<Type> &returnType,
        const SharedPtr<CompoundStmtNode> &body
) : name(std::move(name)),
    params(params),
    returnType(returnType),
    body(body) {}

void FunctionDeclNode::accept(const SharedPtr<ASTVisitor> &visitor) {
    visitor->visit(staticPtrCast<FunctionDeclNode>(shared_from_this()));
}

void FunctionDeclNode::bindChildrenInversely() {
    auto self = shared_from_this();
    for (const SharedPtr<ParmVarDeclNode> &param: params) {
        param->parent = self;
    }
    body->parent = self;
}
