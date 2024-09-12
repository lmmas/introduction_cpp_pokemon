//
// Created by louismmassin on 9/12/24.
//
#ifndef POKEBALL_H
#define POKEBALL_H
#include "SetOfPokemon.hpp"


class Pokeball :public  SetOfPokemon{
public:
    Pokeball() = default;
    unique_ptr<Pokemon> getPokemon(std::string name);
    unique_ptr<Pokemon> getPokemon(int id);
    void addPokemon(unique_ptr<Pokemon> newPokemon);
};



#endif //POKEBALL_H
