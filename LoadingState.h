//
// Created by louismmassin on 9/12/24.
//
#ifndef LOADINGSTATE_H
#define LOADINGSTATE_H
#include "GameState.h"


class LoadingState final : public GameState {
public:
    LoadingState(Game& game);

    void run() override;
    void action1() override;
    void action2() override;
    void action3() override;
};



#endif //LOADINGSTATE_H
