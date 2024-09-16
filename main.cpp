#include <iostream>

#include "Game.h"
#include "Pokedex.h"
#include "Pokemon.hpp"
#include "PokemonParty.h"
using namespace std;
void test1() {
    Pokemon pikachu(0, "Pikachu", Pokemon::ELECTRIC, Pokemon::NONE,1, 2, 3, 0);
    pikachu.displayInfo();
}

void test2() {
    shared_ptr<Pokedex> myPokedex = Pokedex::getInstance();
    //myPokedex ->displayList();
    Pokeball myPokeball{};
    myPokeball.addPokemon(myPokedex->getPokemon("Pikachu"));
    myPokeball.addPokemon(myPokedex->getPokemon("Squirtle"));
    myPokeball.addPokemon(myPokedex->getPokemon("Caterpie"));
    myPokeball.addPokemon(myPokedex->getPokemon("Charizard"));
    myPokeball.addPokemon(myPokedex->getPokemon("Kakuna"));
    myPokeball.addPokemon(myPokedex->getPokemon("Beedrill"));
    myPokeball.addPokemon(myPokedex->getPokemon("Weedle"));
    myPokeball.displayList();
    cout << "..." << endl;
    string names[6] = {"Squirtle", "Caterpie", "Charizard", "Kakuna", "Beedrill", "Weedle"};
    PokemonParty myParty(myPokeball, names);
    myParty.displayList();
}

void test3() {
    Game myGame{};
    myGame.run();
}

int main() {
    test3();
    return 0;
}