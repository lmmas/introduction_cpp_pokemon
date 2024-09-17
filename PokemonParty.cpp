//
// Created by louismmassin on 9/12/24.
//

#include "PokemonParty.h"

#include "UtilityFunctions.h"

PokemonParty::PokemonParty(Pokeball& pokeball, string names[6]): pokeball(pokeball), activePokemon(0){
    for(int i = 0; i <6; i++) {
        list.push_back(pokeball.getPokemon(names[i]));
    }
}

PokemonParty::PokemonParty():pokeball(){};

PokemonParty::PokemonParty(Pokeball& pokeball): pokeball(pokeball) {
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

unique_ptr<Pokemon> PokemonParty::getPokemon(const string &name) {
    for(int i = 0; i < list.size(); i++) {
        if(list.at(i)->getName() == name) {
            unique_ptr<Pokemon> pp = move(list.at(i));
            list.erase(list.begin()+i);
            return pp;
        }
    }
    return nullptr;
}

Pokemon &PokemonParty::getActivePokemon() {
    return *list.at(activePokemon);
}

void PokemonParty::addPokemon(unique_ptr<Pokemon> newPokemon) {
    if(list.size() <PokemonParty::partySize) {
        list.push_back(move(newPokemon));
    }
}

void PokemonParty::switchWithPokeball(int partyIndex, int pokeballIndex) {
    auto tempPokemon = move(list.at(partyIndex));
    list.at(partyIndex) = move(pokeball.getList().at(pokeballIndex));
    pokeball.getList().at(pokeballIndex) = move(tempPokemon);
}

bool PokemonParty::allPokemonsKO() {
    bool exp = true;
    for(const auto& pp: list) {
        exp = exp && pp->isKO();
    }
    return exp;
}

void PokemonParty::setActivePokemon(int index) {
    activePokemon = index;
}

int PokemonParty::findNONKOIndex() {
    int randomIndex = UtilityFunctions::randomInt(list.size());
    if(!list.at(activePokemon)->isKO()) {
        return randomIndex;
    }
    else {
        return findNONKOIndex();
    }
}
