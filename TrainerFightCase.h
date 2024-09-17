//
// Created by louismmassin on 9/17/24.
//

#ifndef TRAINERFIGHTCASE_H
#define TRAINERFIGHTCASE_H
#include "GameState.h"


class TrainerFightCase : public GameState{
private:
    PokemonParty trainerParty;
public:
    TrainerFightCase(Game& game);
    void run() override;
    void action1() override;
    void action2() override;
    void action3() override;
    void action4() override;
    void action5() override;
    void action6() override;
    int findNONKOIndex()
};



#endif //TRAINERFIGHTCASE_H
