#ifndef CONSTANT_H
#define CONSTANT_H

#include "expression.h" 

class Constant : public Expression {
public:
    explicit Constant(double value);
    double evaluate() const override;
    std::string toString() const override;
    std::string getType() const override;
    std::unique_ptr<Expression> clone() const override;

    void setValue(double value);
    double getValue() const;

private:
    double value_;
};

#endif
