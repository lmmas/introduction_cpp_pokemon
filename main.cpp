#include <iostream>
#include "Pokemon.hpp"
int main() {
    Pokemon pikachu(0, "Pikachu", 1, 2, 3, 0);
    pikachu.displayInfo();
    //pikachu.~Pokemon();
    return 0;
}
