//
// Created by louismmassin on 9/12/24.
//
#ifndef POKEMONPARTY_H
#define POKEMONPARTY_H
#include "Pokeball.h"


class PokemonParty : public SetOfPokemon{
private:
    Pokeball& pokeball;
    int activePokemon;
public:
    PokemonParty(Pokeball& pokeball, std::string names[6]);
    PokemonParty(Pokeball& pokeball);
    unique_ptr<Pokemon> getPokemon(const string &name);
    unique_ptr<Pokemon> getPokemon(int id);
    Pokemon& getActivePokemon();
    void addPokemon(unique_ptr<Pokemon> newPokemon);
};



#endif //POKEMONPARTY_H
