#include <iostream>
#include "add.h"
#include "constant.h"

int main() {
    auto expr = std::make_unique<Add>(
        std::make_unique<Constant>(5.0),
        std::make_unique<Constant>(3.0)
    );

    std::cout << "Expression: " << expr->toString() << "\n";    // (5 + 3)
    std::cout << "Type: " << expr->getType() << "\n";           // Add
    std::cout << "Result: " << expr->evaluate() << "\n";        // 8

    return 0;
}
