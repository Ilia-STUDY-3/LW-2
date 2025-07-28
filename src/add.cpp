#include "add.h"

Add::Add(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
    : BinaryOperation(std::move(left), std::move(right)) {}

Value Add::evaluate() const {
    return left_->evaluate() + right_->evaluate();
}

std::string Add::toString() const {
    std::string leftStr = left_->toString();
    std::string rightStr = right_->toString();
    return "(" + leftStr + " + " + rightStr + ")";
}

std::string Add::getType() const {
    return "Add";
}

std::unique_ptr<Expression> Add::clone() const {
    return std::make_unique<Add>(left_->clone(), right_->clone());
}

int Add::getPriority() const {
    return 1;
}

std::string Add::getOperatorSymbol() const {
    return "+";
}

double Add::apply(double left, double right) const {
    return left + right;
}
