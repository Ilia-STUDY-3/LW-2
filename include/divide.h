#ifndef DIVIDE_H
#define DIVIDE_H

#include "binary_operation.h"

class Divide : public BinaryOperation {
public:
    using BinaryOperation::BinaryOperation;

    Value evaluate() const override {
        Value denominator = right_->evaluate();
        if (denominator == 0.0) throw std::runtime_error("Division by zero");
        return left_->evaluate() / denominator;
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
};

#endif // DIVIDE_H
