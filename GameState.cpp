//
// Created by louismmassin on 9/12/24.
//

#include "GameState.h"

GameState::GameState(Game& game): game(game), playerPokeball(game.getPokeball()), playerParty(game.getParty()){
}

GameState::~GameState() {
}


void GameState::promptAction() {
    string action;
    cin >> action;
    if(action == "0") {
        cout << "Exiting game..." << endl;
    }
    else if(action == "1") {
        action1();
    }
    else if(action == "2") {
        action2();
    }
    else if(action == "3") {
        action3();
    }
    else {
        invalidKey();
    }
}

void GameState::invalidKey() {
    cout << "Invalid key" << endl;
    promptAction();
}
