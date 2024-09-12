//
// Created by louismmassin on 9/12/24.
//

#include "Pokedex.h"

Pokedex::Pokedex(std::string csvPath) {
    lireCSV(csvPath);
}

Pokemon Pokedex::getPokemon(int id) {
    for(Pokemon* pp: list) {
        if(pp->getId() == id) {
            return *pp;
        }
    }
    return *list.at(0);
}

Pokemon Pokedex::getPokemon(std::string name) {
    for(Pokemon* pp: list) {
        if(pp->getName() == name) {
            return *pp;
        }
    }
    return *list.at(0);
}


