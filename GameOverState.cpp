//
// Created by louismmassin on 9/15/24.
//

#include "GameOverState.h"

#include "InitState.h"
#include "PokeCenterState.h"

GameOverState::GameOverState(Game &game): GameState(game) {
}

void GameOverState::run() {
    cout << "Game Over!" << endl;
    cout << "'1': respawn in PokeCenter; '2': go to start screen; '2': quit game" << endl;
    promptAction();
}

void GameOverState::action1() {
    cout << "Respawning..." << endl;
    game.transitionToState(make_unique<PokeCenterState>(game));
}

void GameOverState::action2() {
    game.transitionToState(make_unique<InitState>(game));
}

void GameOverState::action3() {
    invalidKey();
}

void GameOverState::action4() {
    invalidKey();
}

void GameOverState::action5() {
    invalidKey();
}

void GameOverState::action6() {
    invalidKey();
}