#include "binary_operation.h"

BinaryOperation::BinaryOperation(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
    : left_(std::move(left)), right_(std::move(right)) {}

void BinaryOperation::setLeft(std::unique_ptr<Expression> left) {
    left_ = std::move(left);
}

void BinaryOperation::setRight(std::unique_ptr<Expression> right) {
    right_ = std::move(right);
}

const Expression* BinaryOperation::getLeft() const {
    return left_.get();
}

const Expression* BinaryOperation::getRight() const {
    return right_.get();
}
