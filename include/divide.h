#ifndef DIVIDE_H
#define DIVIDE_H

#include "binary_operation.h"

class Divide : public BinaryOperation {
public:
    Divide(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
        : BinaryOperation(std::move(left), std::move(right)) {}

    Value evaluate() const override {
        return left_->evaluate() / right_->evaluate();
    }

    std::string toString() const override {
        return "(" + left_->toString() + " / " + right_->toString() + ")";
    }

    std::string getType() const override {
        return "Divide";
    }

    std::unique_ptr<Expression> clone() const override {
        return std::make_unique<Divide>(left_->clone(), right_->clone());
    }

    int getPriority() const override {
        return 2;
    }

    std::string getOperatorSymbol() const override {
        return "/";
    }
};

#endif // DIVIDE_H
