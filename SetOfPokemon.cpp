#include "SetOfPokemon.hpp"
void SetOfPokemon::displayList() {
    for(Pokemon * pp: this->list)
    {
        std::cout << pp->getId() << ", " << pp->getName() << std::endl;
    }
}