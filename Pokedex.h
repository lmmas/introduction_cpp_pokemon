//
// Created by louismmassin on 9/12/24.
//

#ifndef POKEDEX_H
#define POKEDEX_H
#include <string>

#include "SetOfPokemon.hpp"


class Pokedex : public SetOfPokemon{
public:
    Pokemon getPokemon(std::string name);
    Pokemon getPokemon(int id);
    Pokedex(std::string csvPath);
    void lireCSV(std::string csvPath);
};



#endif //POKEDEX_H
