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
class GameState {
protected:
    Game& game;
    Pokeball& playerPokeball;
    PokemonParty& playerParty;
public:
    GameState(Game& game);
    virtual ~GameState();
    void promptAction();
    void invalidKey();
    virtual void action1() =0;
    virtual void action2() = 0;
    virtual void action3() = 0;
    virtual void run() = 0;
};



#endif //GAMESTATE_H
