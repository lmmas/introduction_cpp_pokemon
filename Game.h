//
// Created by louismmassin on 9/12/24.
//
#ifndef GAME_H
#define GAME_H
#include "GameState.h"
#include "Pokeball.h"
#include "Pokedex.h"
#include "PokemonParty.h"
using namespace std;

class GameState;
class Game {
private:
    unique_ptr<GameState> currentState;
    Pokeball playerPokeball;
    PokemonParty playerParty;
    shared_ptr<Pokedex> gamePokedex;
public:
    Game();
    Pokeball& getPokeball();
    PokemonParty& getParty();
    void transitionToState(unique_ptr<GameState> newState);
    void action1();
    void action2();
    void action3();
    void run();
};


#endif //GAME_H
