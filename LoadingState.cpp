//
// Created by louismmassin on 9/12/24.
//
#include "LoadingState.h"

#include <iostream>

#include "InitState.h"

LoadingState::LoadingState(const shared_ptr<Game>& game): GameState(game) {
    cout << "Loading..." << endl;
}

void LoadingState::actionStart() {
    auto anotherState = make_unique<InitState>(this->game);
    game->transitionToState(move(anotherState));
}

void LoadingState::actionGo() {

}
