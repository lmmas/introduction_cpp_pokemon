//
// Created by louismmassin on 9/12/24.
//
#ifndef POKEMONPARTY_H
#define POKEMONPARTY_H
#include "Pokeball.h"


class PokemonParty : public SetOfPokemon{
private:
    Pokeball& pokeball;
public:
    PokemonParty(Pokeball& pokeball, std::string names[6]);
    unique_ptr<Pokemon> getPokemon(std::string name);
    unique_ptr<Pokemon> getPokemon(int id);
};



#endif //POKEMONPARTY_H
