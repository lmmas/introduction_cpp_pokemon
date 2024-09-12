//
// Created by louismmassin on 9/12/24.
//

#include "InitState.h"

#include <iostream>
#include <utility>

InitState::InitState(const shared_ptr<Game>& game): GameState(game) {
    cout<< "Pokemon start!!!" << endl;
}


void InitState::actionStart() {
}

void InitState::actionGo() {

}

