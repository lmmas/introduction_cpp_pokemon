//
// Created by louismmassin on 9/12/24.
//
#ifndef POKEDEX_H
#define POKEDEX_H
#include <string>

#include "SetOfPokemon.hpp"

using namespace std;

class Pokedex : public SetOfPokemon{
private:
    static shared_ptr<Pokedex> instance;
    Pokedex(string csvPath);
    void lireCSV(string csvPath);
public:
    Pokedex(const Pokedex& other) = delete;
    void operator=(const Pokedex & ) = delete;
    unique_ptr<Pokemon> getPokemon(const string& name) override;
    unique_ptr<Pokemon> getPokemon(int id) override;
    unique_ptr<Pokemon> randomPokemon();
    static shared_ptr<Pokedex> getInstance();
};



#endif //POKEDEX_H
