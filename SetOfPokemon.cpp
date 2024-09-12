#include "SetOfPokemon.hpp"
void SetOfPokemon::displayList() {
    for(const auto& pp: this->list)
    {
        cout << "Pokemon #" << pp->getId() << ": " << pp->getName() << endl;
    }
}