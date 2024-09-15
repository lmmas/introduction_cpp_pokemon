//
// Created by louismmassin on 9/12/24.
//

#ifndef FIGHTSTATE_H
#define FIGHTSTATE_H
#include "GameState.h"


class FightState : public GameState{
private:
    unique_ptr<Pokemon> wildPokemon;
    bool flightSuccess;
    void flee();
public:
    FightState(Game& game);
    void run() override;
    void action1() override;
    void action2() override;
    void action3() override;
};



#endif //FIGHTSTATE_H
