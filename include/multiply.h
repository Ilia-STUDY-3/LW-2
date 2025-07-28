#pragma once
#include "binary_operation.h"

class Multiply : public BinaryOperation {
public:
    Multiply(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
        : BinaryOperation(std::move(left), std::move(right)) {}

    Value evaluate() const override {
        return left_->evaluate() * right_->evaluate();
    }

    std::string getOperatorSymbol() const override {
        return "*";
    }

    int getPriority() const override {
        return 2;
    }

    std::string toString() const override {
        std::string leftStr = left_->toString();
        std::string rightStr = right_->toString();

        if (auto* leftOp = dynamic_cast<BinaryOperation*>(left_.get())) {
            if (leftOp->getPriority() < getPriority())
                leftStr = "(" + leftStr + ")";
        }

        if (auto* rightOp = dynamic_cast<BinaryOperation*>(right_.get())) {
            if (rightOp->getPriority() < getPriority())
                rightStr = "(" + rightStr + ")";
        }

        return leftStr + " * " + rightStr;
    }

    std::string getType() const override {
        return "Multiply";
    }

    std::unique_ptr<Expression> clone() const override {
        return std::make_unique<Multiply>(left_->clone(), right_->clone());
    }

protected:
    double apply(double left, double right) const override {
        return left * right;
    }
};
