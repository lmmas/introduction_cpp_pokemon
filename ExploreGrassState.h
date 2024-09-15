//
// Created by louismmassin on 9/12/24.
//

#ifndef EXPLOREGRASSSTATE_H
#define EXPLOREGRASSSTATE_H
#include <memory>

#include "Game.h"


class ExploreGrassState final : public GameState {
public:
    ExploreGrassState(Game& game);
    void run() override;
    void action1() override;
    void action2() override;
    void action3() override;
};



#endif //EXPLOREGRASSSTATE_H
