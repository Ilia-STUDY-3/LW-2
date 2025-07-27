#include <iostream>
#include "constant.h"
#include "multiply.h"
#include "divide.h"

int main() {
    auto mulExpr = std::make_unique<Multiply>(
        std::make_unique<Constant>(6),
        std::make_unique<Constant>(7)
    );

    std::cout << mulExpr->toString() << " = " << mulExpr->evaluate() << std::endl;

    auto divExpr = std::make_unique<Divide>(
        std::make_unique<Constant>(20),
        std::make_unique<Constant>(5)
    );

    std::cout << divExpr->toString() << " = " << divExpr->evaluate() << std::endl;

    return 0;
}
