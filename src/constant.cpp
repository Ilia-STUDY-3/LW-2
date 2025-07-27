#include "constant.h"
#include <sstream>

Constant::Constant(double value) : value_(value) {}

double Constant::evaluate() const { return value_; }

std::string Constant::toString() const {
    std::ostringstream oss;
    oss << value_;
    return oss.str();
}

std::string Constant::getType() const { return "Constant"; }

std::unique_ptr<Expression> Constant::clone() const {
    return std::make_unique<Constant>(value_);
}

void Constant::setValue(double value) { value_ = value; }

double Constant::getValue() const { return value_; }
