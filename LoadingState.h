//
// Created by louismmassin on 9/12/24.
//
#ifndef LOADINGSTATE_H
#define LOADINGSTATE_H
#include "GameState.h"


class LoadingState: public GameState {
public:
    LoadingState(const shared_ptr<Game>& game);
    void actionStart() override;
    void actionGo() override;
};



#endif //LOADINGSTATE_H
