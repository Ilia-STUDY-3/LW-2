#include <iostream>
#include "constant.h"
#include "negate.h"

int main() {
    auto negExpr = std::make_unique<Negate>(
        std::make_unique<Constant>(10)
    );

    std::cout << negExpr->toString() << " = " << negExpr->evaluate() << std::endl;

    return 0;
}
