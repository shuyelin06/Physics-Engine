#include <iostream>

#include "core/Simulator.hpp"

int main() {
    std::cout << "Application Running";

    Simulator simulator = Simulator("Testing :D");

    while( simulator.isActive() ) {
        simulator.update();
    }

    std::cout << "Application End";
    return 0;
}