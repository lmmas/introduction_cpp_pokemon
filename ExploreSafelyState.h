//
// Created by louismmassin on 9/12/24.
//

#ifndef EXPLORESAFELYSTATE_H
#define EXPLORESAFELYSTATE_H
#include "GameState.h"


class ExploreSafelyState final : public GameState {
public:
    ExploreSafelyState(Game& game);

    void run() override;
    void action1() override;
    void action2() override;
    void action3() override;
    void action4() override;
    void action5() override;
    void action6() override;
};



#endif //EXPLORESAFELYSTATE_H
