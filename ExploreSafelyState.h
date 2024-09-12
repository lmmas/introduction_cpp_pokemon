//
// Created by louismmassin on 9/12/24.
//

#ifndef EXPLORESAFELYSTATE_H
#define EXPLORESAFELYSTATE_H
#include "GameState.h"


class ExploreSafelyState: public GameState {
public:
    ExploreSafelyState(const shared_ptr<Game>& game);
    void actionStart() override;
    void actionGo() override;
};



#endif //EXPLORESAFELYSTATE_H
