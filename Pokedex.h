//
// Created by louismmassin on 9/12/24.
//

#ifndef POKEDEX_H
#define POKEDEX_H
#include <string>

#include "SetOfPokemon.hpp"


class Pokedex : public SetOfPokemon{
private:
    static Pokedex* instance;
    Pokedex(std::string csvPath);
public:
    Pokedex(Pokedex& other) = delete;
    void operator=(const Pokedex & ) = delete;
    std::unique_ptr<Pokemon> getPokemon(std::string name);
    std::unique_ptr<Pokemon> getPokemon(int id);

    void lireCSV(std::string csvPath);
    static Pokedex* getInstance();
};



#endif //POKEDEX_H
