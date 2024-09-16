//
// Created by louismmassin on 9/12/24.
//

#ifndef FIGHTSTATE_H
#define FIGHTSTATE_H
#include "GameState.h"


class WildFightState : public GameState{
private:
    unique_ptr<Pokemon> wildPokemon;
    bool flightSuccess = false;
    bool catchSuccess = false;
    void flee();
public:
    WildFightState(Game& game);
    void run() override;
    void action1() override;
    void action2() override;
    void action3() override;
};



#endif //FIGHTSTATE_H
