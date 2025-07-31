#ifndef NEGATE_H
#define NEGATE_H

#include "expression.h"

class Negate : public Expression {
private:
    std::unique_ptr<Expression> operand;

public:
    explicit Negate(std::unique_ptr<Expression> expr);

    Value evaluate() const override;
    std::string toString() const override;
    std::string getType() const override;
    std::unique_ptr<Expression> clone() const override;

    Expression* getOperand() const;
    void setOperand(std::unique_ptr<Expression> newOperand);
};

#endif // NEGATE_H
