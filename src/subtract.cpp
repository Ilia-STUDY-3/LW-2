#include "subtract.h"

Subtract::Subtract(std::unique_ptr<Expression> left_, std::unique_ptr<Expression> right_)
    : BinaryOperation(std::move(left_), std::move(right_)) {}

Value Subtract::evaluate() const {
    return left_->evaluate() - right_->evaluate();
}

std::string Subtract::toString() const {
    std::string leftStr = left_->toString();
    std::string rightStr = right_->toString();
    return "(" + leftStr + " - " + rightStr + ")";
}

std::string Subtract::getType() const {
    return "Subtract";
}

std::unique_ptr<Expression> Subtract::clone() const {
    return std::make_unique<Subtract>(left_->clone(), right_->clone());
}

int Subtract::getPriority() const {
    return 1; // тот же приоритет, что и у Add
}

std::string Subtract::getOperatorSymbol() const {
    return "-";
}
