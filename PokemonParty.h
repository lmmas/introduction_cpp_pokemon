//
// Created by louismmassin on 9/12/24.
//
#ifndef POKEMONPARTY_H
#define POKEMONPARTY_H
#include "Pokeball.h"


class PokemonParty : public SetOfPokemon{
private:
    Pokeball& pokeball;
    int activePokemon = 0;
public:
    static constexpr int partySize = 6;
    PokemonParty(Pokeball& pokeball, string names[6]);
    PokemonParty(Pokeball& pokeball);
    unique_ptr<Pokemon> getPokemon(const string &name) override;
    unique_ptr<Pokemon> getPokemon(int id) override;
    Pokemon& getActivePokemon();
    void setActivePokemon(int index);
    void addPokemon(unique_ptr<Pokemon> newPokemon);
    void switchWithPokeball(int partyIndex, int pokeballIndex);
    bool allPokemonsKO();
    int findNONKOIndex();
};



#endif //POKEMONPARTY_H
