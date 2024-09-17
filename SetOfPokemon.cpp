#include "SetOfPokemon.hpp"
void SetOfPokemon::displayList() {
    for(int i = 0; i < list.size(); i++)
    {
        const auto & pp = list.at(i);
        cout << i+1 << ": " << pp->getName() << " (#" << pp->getId() << ")" << endl;
    }
}

vector<unique_ptr<Pokemon> >& SetOfPokemon::getList() {
    return this->list;
}
