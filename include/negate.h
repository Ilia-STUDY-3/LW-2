#ifndef NEGATE_H
#define NEGATE_H

#include "expression.h"

class Negate : public Expression {
private:
    std::unique_ptr<Expression> operand;

public:
    explicit Negate(std::unique_ptr<Expression> expr) : operand(std::move(expr)) {}

    Value evaluate() const override {
        return -operand->evaluate();
    }

    std::string toString() const override {
        return "(-" + operand->toString() + ")";
    }

    std::string getType() const override {
        return "Negate";
    }

    std::unique_ptr<Expression> clone() const override {
        return std::make_unique<Negate>(operand->clone());
    }

    Expression* getOperand() const {
        return operand.get();
    }

    void setOperand(std::unique_ptr<Expression> newOperand) {
        operand = std::move(newOperand);
    }
};

#endif // NEGATE_H
