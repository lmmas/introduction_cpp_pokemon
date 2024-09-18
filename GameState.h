//
// Created by louismmassin on 9/12/24.
//
#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <memory>

#include "Game.h"

using namespace std;

class Pokeball;
class PokemonParty;
class Game;
class SetOfPokemon;
class GameState {
protected:
    Game& game;
    Pokeball& playerPokeball;
    PokemonParty& playerParty;
public:
    GameState(Game& game);
    virtual ~GameState();
    void promptAction();
    int selectFromListPrompt(int range);
    void invalidKey();
    virtual void action1() = 0;
    virtual void action2() = 0;
    virtual void action3() = 0;
    virtual void action4() = 0;
    virtual void action5() = 0;
    virtual void action6() = 0;
    virtual void run() = 0;
    int selectNonKOPrompt(SetOfPokemon& pokemonList);
};



#endif //GAMESTATE_H
