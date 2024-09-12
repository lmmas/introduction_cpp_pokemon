//
// Created by louismmassin on 9/12/24.
//

#include "GameState.h"

#include <utility>

GameState::GameState(const shared_ptr<Game>& game){
    this->game = shared_ptr<Game>(game);
}
