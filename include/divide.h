#ifndef DIVIDE_H
#define DIVIDE_H

#include "binary_operation.h"

class Divide : public BinaryOperation {
public:
    Divide(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
        : BinaryOperation(std::move(left), std::move(right)) {}

    Value evaluate() const override;

    std::string toString() const override;

    std::string getType() const override;

    std::unique_ptr<Expression> clone() const override;

    int getPriority() const override;

    std::string getOperatorSymbol() const override;

protected:
    double apply(double left, double right) const override {
        // Можно добавить проверку на деление на 0, если хочешь
        return left / right;
    }
};

#endif // DIVIDE_H
