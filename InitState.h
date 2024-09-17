//
// Created by louismmassin on 9/12/24.
//
#ifndef INITSTATE_H
#define INITSTATE_H
#include "GameState.h"


class InitState final : public GameState {
public:
    InitState(Game& game);
    void run() override;
    void action1() override;
    void action2() override;
    void action3() override;
    void action4() override;
    void action5() override;
    void action6() override;
};



#endif //INITSTATE_H
