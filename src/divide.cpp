#include "divide.h"

Value Divide::evaluate() const {
    return left_->evaluate() / right_->evaluate(); // Можно оставить, либо удалить — зависит от твоего стиля
}

std::string Divide::toString() const {
    return BinaryOperation::toString();
}

std::string Divide::getType() const {
    return "Divide";
}

std::unique_ptr<Expression> Divide::clone() const {
    return std::make_unique<Divide>(left_->clone(), right_->clone());
}

int Divide::getPriority() const {
    return 2; // такой же приоритет, как у умножения
}

std::string Divide::getOperatorSymbol() const {
    return "/";
}
