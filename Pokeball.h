//
// Created by louismmassin on 9/12/24.
//

#ifndef POKEBALL_H
#define POKEBALL_H
#include "SetOfPokemon.hpp"


class Pokeball :public  SetOfPokemon{
public:
    Pokeball() = default;
    std::unique_ptr<Pokemon> getPokemon(std::string name);
    std::unique_ptr<Pokemon> getPokemon(int id);
};



#endif //POKEBALL_H
