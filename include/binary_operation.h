#ifndef BINARY_OPERATION_H
#define BINARY_OPERATION_H

#include "expression.h"
#include <memory>

class BinaryOperation : public Expression {
public:
    BinaryOperation(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right);

    void setLeft(std::unique_ptr<Expression> left);
    void setRight(std::unique_ptr<Expression> right);

    const Expression* getLeft() const;
    const Expression* getRight() const;

protected:
    std::unique_ptr<Expression> left_;
    std::unique_ptr<Expression> right_;

    // Приоритет нужен для правильной расстановки скобок
    virtual int getPriority() const = 0;

    // Символ операции, например "+"
    virtual std::string getOperatorSymbol() const = 0;
};

#endif // BINARY_OPERATION_H
