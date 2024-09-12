//
// Created by louismmassin on 9/12/24.
//

#include "Game.h"

#include "InitState.h"
#include "LoadingState.h"

Game::Game() {
    this->currentState = make_unique<LoadingState>(shared_ptr<Game>(this));
}

void Game::transitionToState(unique_ptr<GameState> newState) {
    currentState = move(newState);
}

void Game::actionStart() {
    this->currentState->actionStart();
}
