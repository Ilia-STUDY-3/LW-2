#include <iostream>
#include "add.h"
#include "subtract.h"
#include "constant.h"

int main() {
    auto addExpr = std::make_unique<Add>(
        std::make_unique<Constant>(5.0),
        std::make_unique<Constant>(3.0)
    );

    auto subExpr = std::make_unique<Subtract>(
        std::make_unique<Constant>(10.0),
        std::make_unique<Constant>(4.0)
    );

    std::cout << "Add: " << addExpr->toString()
              << " = " << addExpr->evaluate() << "\n";

    std::cout << "Subtract: " << subExpr->toString()
              << " = " << subExpr->evaluate() << "\n";

    return 0;
}
