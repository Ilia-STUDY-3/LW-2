#include "variable.h"
#include <sstream>

Variable::Variable(Value* ptr) : valuePtr_(ptr) {}

Value Variable::evaluate() const {
    return valuePtr_ ? *valuePtr_ : 0.0;
}

std::string Variable::toString() const {
    std::ostringstream oss;
    oss << "var(" << (valuePtr_ ? std::to_string(*valuePtr_) : "null") << ")";
    return oss.str();
}

std::string Variable::getType() const {
    return "Variable";
}

std::unique_ptr<Expression> Variable::clone() const {
    return std::make_unique<Variable>(valuePtr_);
}

void Variable::setPointer(Value* ptr) {
    valuePtr_ = ptr;
}

Value* Variable::getPointer() const {
    return valuePtr_;
}
