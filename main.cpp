#include <iostream>
#include "constant.h"
#include "add.h"
#include "multiply.h"
#include "subtract.h"

int main() {
    // 8 * 7
    auto multInner = std::make_unique<Multiply>(
        std::make_unique<Constant>(8),
        std::make_unique<Constant>(7)
    );

    // 3 - (8 * 7)
    auto sub = std::make_unique<Subtract>(
        std::make_unique<Constant>(3),
        std::move(multInner)
    );

    // 20 * (3 - 8 * 7)
    auto multOuter = std::make_unique<Multiply>(
        std::make_unique<Constant>(20),
        std::move(sub)
    );

    // 10 + [результат]
    auto expr = std::make_unique<Add>(
        std::make_unique<Constant>(10),
        std::move(multOuter)
    );

    std::cout << expr->toString() << "=" << expr->evaluate() << std::endl;
}
