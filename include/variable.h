#ifndef VARIABLE_H
#define VARIABLE_H

#include "expression.h"

class Variable : public Expression {
public:
    explicit Variable(Value* ptr);

    Value evaluate() const override;
    std::string toString() const override;
    std::string getType() const override;
    std::unique_ptr<Expression> clone() const override;

    void setPointer(Value* ptr);
    Value* getPointer() const;

private:
    Value* valuePtr_;
};

#endif // VARIABLE_H
