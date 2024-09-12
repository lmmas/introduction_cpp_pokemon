//
// Created by louismmassin on 9/12/24.
//

#include "PokemonParty.h"

PokemonParty::PokemonParty(Pokeball& pokeball, string names[6]): pokeball(pokeball) {
    for(int i = 0; i <6; i++) {
        list.push_back(pokeball.getPokemon(names[i]));
    }
}


unique_ptr<Pokemon> PokemonParty::getPokemon(int id) {
    for(int i = 0; i < list.size(); i++) {
        if(list.at(i)->getId() == id) {
            unique_ptr<Pokemon> pp = move(list.at(i));
            list.erase(list.begin()+i);
            return pp;
        }
    }
    return nullptr;
}

unique_ptr<Pokemon> PokemonParty::getPokemon(string name) {
    for(int i = 0; i < list.size(); i++) {
        if(list.at(i)->getName() == name) {
            unique_ptr<Pokemon> pp = move(list.at(i));
            list.erase(list.begin()+i);
            return pp;
        }
    }
    return nullptr;
}