//
// Created by louismmassin on 9/12/24.
//
#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <memory>

#include "Game.h"

//#include "Game.h"
using namespace std;

class Game;
class GameState {
protected:
    shared_ptr<Game> game;
public:
    GameState(const shared_ptr<Game>& game);
    virtual void actionStart() =0;
    virtual void actionGo() = 0;
};



#endif //GAMESTATE_H
