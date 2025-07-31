#include "binary_operation.h"

BinaryOperation::BinaryOperation(std::unique_ptr<Expression> left_, std::unique_ptr<Expression> right_)
    : left_(std::move(left_)), right_(std::move(right_)) {}

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
