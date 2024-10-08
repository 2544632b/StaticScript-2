#pragma once

#include "Entity/Scope.h"
#include "Sema/ASTVisitor.h"

/// 作用域扫描器
class ScopeScanner final : public ASTVisitorWithScope {
public:
    void visit(const SharedPtr<ModuleNode> &module) override;

    void visit(const SharedPtr<VarDeclNode> &varDecl) override;

    void visit(const SharedPtr<ParmVarDeclNode> &paramVarDecl) override;

    void visit(const SharedPtr<FunctionDeclNode> &funcDecl) override;

    void visit(const SharedPtr<BooleanLiteralExprNode> &boolLiteralExpr) override;

    void visit(const SharedPtr<IntegerLiteralExprNode> &intLiteralExpr) override;

    void visit(const SharedPtr<FloatLiteralExprNode> &floatLiteralExpr) override;

    void visit(const SharedPtr<StringLiteralExprNode> &strLiteralExpr) override;

    void visit(const SharedPtr<ArrayLiteralExprNode> &arrayLiteralExpr) override;

    void visit(const SharedPtr<IdentifierExprNode> &varExpr) override;

    void visit(const SharedPtr<CallExprNode> &callExpr) override;

    void visit(const SharedPtr<UnaryOperatorExprNode> &uopExpr) override;

    void visit(const SharedPtr<BinaryOperatorExprNode> &bopExpr) override;

    void visit(const SharedPtr<TernaryOperatorExprNode> &topExpre) override;

    void visit(const SharedPtr<ArraySubscriptExprNode> &asExpr) override;

    void visit(const SharedPtr<ExprStmtNode> &exprStmt) override;

    void visit(const SharedPtr<CompoundStmtNode> &compStmt) override;

    void visit(const SharedPtr<VarDeclStmtNode> &varDeclStmt) override;

    void visit(const SharedPtr<FunctionDeclStmtNode> &funcDeclStmt) override;

    void visit(const SharedPtr<IfStmtNode> &ifStmt) override;

    void visit(const SharedPtr<WhileStmtNode> &whileStmt) override;

    void visit(const SharedPtr<ForStmtNode> &forStmt) override;

    void visit(const SharedPtr<ContinueStmtNode> &continueStmt) override;

    void visit(const SharedPtr<BreakStmtNode> &breakStmt) override;

    void visit(const SharedPtr<ReturnStmtNode> &returnStmt) override;
};