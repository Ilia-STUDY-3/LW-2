#ifndef ADD_H
#define ADD_H

#include "binary_operation.h"

class Add : public BinaryOperation {
public:
    Add(std::unique_ptr<Expression> left_, std::unique_ptr<Expression> right_);

    Value evaluate() const override;
    std::string toString() const override;
    std::string getType() const override;
    std::unique_ptr<Expression> clone() const override;

protected:
    int getPriority() const override;
    std::string getOperatorSymbol() const override;
};

#endif // ADD_H
