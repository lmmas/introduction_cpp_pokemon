//
// Created by louismmassin on 9/12/24.
//
#ifndef INITSTATE_H
#define INITSTATE_H
#include "GameState.h"


class InitState: public GameState {
public:
    InitState(const shared_ptr<Game>& game);
    void actionStart() override;
    void actionGo() override;
};



#endif //INITSTATE_H
