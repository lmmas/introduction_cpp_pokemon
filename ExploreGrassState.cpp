//
// Created by louismmassin on 9/12/24.
//

#include "ExploreGrassState.h"

#include "ExploreSafelyState.h"
#include "WildFightState.h"
#include "UtilityFunctions.h"

ExploreGrassState::ExploreGrassState(Game &game): GameState(game) {
}

void ExploreGrassState::run() {
    cout << "Exploring in the tall grass!!" << endl;
    cout << "1: explore further; 2: return to safe area" << endl;
    promptAction();
}
void ExploreGrassState::action1() {
    if(UtilityFunctions::randomEvent(0.3f)) {
        game.transitionToState(make_unique<WildFightState>(game));
    }
    else {
        run();
    }
}

void ExploreGrassState::action2() {
    auto anotherState = make_unique<ExploreSafelyState>(this->game);
    game.transitionToState(move(anotherState));
}

void ExploreGrassState::action3() {
    invalidKey();
}