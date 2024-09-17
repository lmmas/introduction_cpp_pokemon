//
// Created by louismmassin on 9/16/24.
//

#ifndef POKECENTERSTATE_H
#define POKECENTERSTATE_H
#include "GameState.h"


class PokeCenterState: public GameState {
public:
    PokeCenterState(Game& game);
    void run() override;
    void action1() override;
    void action2() override;
    void action3() override;
    void action4() override;
    void action5() override;
    void action6() override;
};



#endif //POKECENTERSTATE_H
