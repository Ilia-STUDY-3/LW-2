#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "binary_operation.h"

class Multiply : public BinaryOperation {
public:
    using BinaryOperation::BinaryOperation;

    Value evaluate() const override {
        return left->evaluate() * right->evaluate();
    }

    std::string toString() const override {
        return "(" + left->toString() + " * " + right->toString() + ")";
    }

    std::string getType() const override {
        return "Multiply";
    }

    std::unique_ptr<Expression> clone() const override {
        return std::make_unique<Multiply>(left->clone(), right->clone());
    }
};

#endif // MULTIPLY_H
