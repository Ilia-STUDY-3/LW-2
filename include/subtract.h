#ifndef SUBTRACT_H
#define SUBTRACT_H

#include "binary_operation.h"

class Subtract : public BinaryOperation {
public:
    Subtract(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right);

    Value evaluate() const override;
    std::string toString() const override;
    std::string getType() const override;
    std::unique_ptr<Expression> clone() const override;

protected:
    int getPriority() const override;
    std::string getOperatorSymbol() const override;
};

#endif // SUBTRACT_H

