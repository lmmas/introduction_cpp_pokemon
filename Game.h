//
// Created by louismmassin on 9/12/24.
//
#ifndef GAME_H
#define GAME_H
#include "GameState.h"
using namespace std;

class GameState;
class Game {
private:
    unique_ptr<GameState> currentState;
public:
    Game();
    void transitionToState(unique_ptr<GameState> newState);
    void actionStart();
};


#endif //GAME_H
