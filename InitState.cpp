//
// Created by louismmassin on 9/12/24.
//

#include "InitState.h"

#include <iostream>

#include "ExploreSafelyState.h"

InitState::InitState(Game& game): GameState(game) {
    cout<< "Pokemon start!!!" << endl;
}

void InitState::run() {
    cout << "type '1' to start" << endl;
    promptAction();
}

void InitState::action1() {
    game.transitionToState(move(make_unique<ExploreSafelyState>(game)));
}

void InitState::action2() {
    invalidKey();
}

void InitState::action3() {
    invalidKey();
}