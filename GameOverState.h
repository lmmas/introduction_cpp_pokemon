//
// Created by louismmassin on 9/15/24.
//

#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include "GameState.h"

using namespace std;

class GameOverState: public GameState {
public:
    GameOverState(Game& game);
    void run() override;
    void action1() override;
    void action2() override;
    void action3() override;
    void action4() override;
    void action5() override;
    void action6() override;
};



#endif //GAMEOVERSTATE_H
