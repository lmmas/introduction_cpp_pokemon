//
// Created by louismmassin on 9/12/24.
//

#include "ExploreSafelyState.h"

ExploreSafelyState::ExploreSafelyState(const shared_ptr<Game> &game): GameState(game) {
    this->game = shared_ptr<Game>(game);
}

void ExploreSafelyState::actionStart() {

}

void ExploreSafelyState::actionGo() {

}
