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
    else if(action == "4") {
        action4();
    }
    else if(action == "5") {
        action5();
    }
    else if(action == "6") {
        action6();
    }
    else {
        invalidKey();
    }
}

void GameState::invalidKey() {
    cout << "Invalid key" << endl;
    promptAction();
}

int GameState::selectFromListPrompt(const int range) {
    int index;
    cin >> index;
    if(index > 0 && index < range + 1) {
        return index - 1;
    }
    else {
        cout << "Invalid key" << endl;
        return selectFromListPrompt(range);
    }
}

int GameState::selectNonKOPrompt(SetOfPokemon &pokemonList) {
    cout << "Select Pokemon for fighting:" << endl;
    pokemonList.displayList();
    int selectedIndex = selectFromListPrompt(pokemonList.getList().size());
    if(!pokemonList.getList().at(selectedIndex)->isKO()) {
        return selectedIndex;
    }
    else {
        cout << "Pokemon is KO!" << endl;
        return selectNonKOPrompt(pokemonList);
    }
}