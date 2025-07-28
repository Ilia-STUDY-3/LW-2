#ifndef BINARY_OPERATION_H
#define BINARY_OPERATION_H

#include "expression.h"
#include <memory>
#include <string>

class BinaryOperation : public Expression {
public:
    BinaryOperation(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
        : left_(std::move(left)), right_(std::move(right)) {}

    double evaluate() const override {
        return apply(left_->evaluate(), right_->evaluate());
    }

    std::string toString() const override {
        std::string leftStr = left_->toString();
        std::string rightStr = right_->toString();

        if (auto* leftOp = dynamic_cast<BinaryOperation*>(left_.get())) {
            if (leftOp->getPriority() < getPriority()) {
                leftStr = "(" + leftStr + ")";
            }
        }

        if (auto* rightOp = dynamic_cast<BinaryOperation*>(right_.get())) {
            if (rightOp->getPriority() <= getPriority()) {
                rightStr = "(" + rightStr + ")";
            }
        }

        return leftStr + " " + getOperatorSymbol() + " " + rightStr;
    }

    std::string getType() const override {
        return getOperatorSymbol();
    }

    virtual std::unique_ptr<Expression> clone() const = 0;

    virtual int getPriority() const = 0;
    virtual std::string getOperatorSymbol() const = 0;

protected:
    virtual double apply(double left, double right) const = 0;

    std::unique_ptr<Expression> left_;
    std::unique_ptr<Expression> right_;
};

#endif // BINARY_OPERATION_H
