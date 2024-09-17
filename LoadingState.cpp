//
// Created by louismmassin on 9/12/24.
//
#include "LoadingState.h"

#include <iostream>

#include "InitState.h"

LoadingState::LoadingState(Game& game): GameState(game) {
    cout << "Loading..." << endl;
}
void LoadingState::run() {
    sleep(1);
    auto anotherState = make_unique<InitState>(this->game);
    game.transitionToState(move(anotherState));
}
void LoadingState::action1() {

}

void LoadingState::action2() {

}

void LoadingState::action3() {

}

void LoadingState::action4() {

}

void LoadingState::action5() {

}

void LoadingState::action6() {

}