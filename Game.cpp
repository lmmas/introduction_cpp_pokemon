//
// Created by louismmassin on 9/12/24.
//

#include "Game.h"
#include "InitState.h"
#include "LoadingState.h"

Game::Game() : playerParty(playerPokeball), gamePokedex(Pokedex::getInstance()){
    currentState = make_unique<LoadingState>(*this);
    playerParty.addPokemon(Pokedex::getInstance()->getPokemon("Pikachu"));
}

Pokeball &Game::getPokeball() {
    return this->playerPokeball;
}


PokemonParty &Game::getParty() {
    return this->playerParty;
}


void Game::transitionToState(unique_ptr<GameState> newState) {
    currentState = move(newState);
    currentState->run();
}

void Game::action1() {
    this->currentState->action1();
}

void Game::action2() {
    this->currentState->action2();
}

void Game::action3() {
    this->currentState->action3();
}

void Game::run() {
    currentState->run();
}
