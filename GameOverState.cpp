//
// Created by louismmassin on 9/15/24.
//

#include "GameOverState.h"

#include "InitState.h"

GameOverState::GameOverState(Game &game): GameState(game) {
}

void GameOverState::run() {
    cout << "Game Over!" << endl;
    cout << "'1': go to start screen; '2': quit game" << endl;
    promptAction();
}

void GameOverState::action1() {
    game.transitionToState(make_unique<InitState>(game));
}

void GameOverState::action2() {

}

void GameOverState::action3() {
    invalidKey();
}
