#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <memory>

using Value = double;

class Expression {
public:
    virtual ~Expression() = default;

    virtual Value evaluate() const = 0;
    virtual std::string toString() const = 0;
    virtual std::string getType() const = 0;
    virtual std::unique_ptr<Expression> clone() const = 0;
};

#endif // EXPRESSION_H
