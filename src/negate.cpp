#include "negate.h"

Negate::Negate(std::unique_ptr<Expression> expr)
    : operand(std::move(expr)) {}

Value Negate::evaluate() const {
    return -operand->evaluate();
}

std::string Negate::toString() const {
    return "(-" + operand->toString() + ")";
}

std::string Negate::getType() const {
    return "Negate";
}

std::unique_ptr<Expression> Negate::clone() const {
    return std::make_unique<Negate>(operand->clone());
}

Expression* Negate::getOperand() const {
    return operand.get();
}

void Negate::setOperand(std::unique_ptr<Expression> newOperand) {
    operand = std::move(newOperand);
}
