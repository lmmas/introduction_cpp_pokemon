#include <iostream>

#include "Pokedex.h"
#include "Pokemon.hpp"
using namespace std;
int main() {
    Pokedex* pokedex_ = Pokedex::getInstance();
    pokedex_ ->displayList();
    Pokemon pikachu(0, "Pikachu", 1, 2, 3, 0);
    pikachu.displayInfo();
    string names[6] = {"Squirtle", "Caterpie", "Charizard", "Kakuna", "Beedrill", "Weedle"};
    return 0;
}
