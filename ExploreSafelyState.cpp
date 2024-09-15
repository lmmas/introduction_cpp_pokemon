//
// Created by louismmassin on 9/12/24.
//

#include "ExploreSafelyState.h"

#include "ExploreGrassState.h"
#include "InitState.h"

ExploreSafelyState::ExploreSafelyState(Game& game): GameState(game) {
}

void ExploreSafelyState::run() {
    cout << "Exploration starts!" << endl;
    cout << "'1': go in tall grass; '3': back to game start" << endl;
    promptAction();
}

void ExploreSafelyState::action1() {
    auto anotherState = make_unique<ExploreGrassState>(this->game);
    game.transitionToState(move(anotherState));
}

void ExploreSafelyState::action2() {
    invalidKey();
}

void ExploreSafelyState::action3() {
    auto anotherState = make_unique<InitState>(this->game);
    game.transitionToState(move(anotherState));
}