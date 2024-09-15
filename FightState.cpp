//
// Created by louismmassin on 9/12/24.
//

#include "FightState.h"

#include "ExploreGrassState.h"
#include "GameOverState.h"
#include "UtilityFunctions.h"


FightState::FightState(Game& game): GameState(game), flightSuccess(false) {
    wildPokemon = Pokedex::getInstance()->randomPokemon();
    cout << "A wild " << wildPokemon->getName() << " appears!" << endl;
    cout << "Go " << playerParty.getActivePokemon().getName() << "!" << endl;
}

void FightState::run() {
    cout << "'1': attack; '2': throw Pokeball; '3': flee" << endl;
    promptAction();
    if(flightSuccess) {
        game.transitionToState(make_unique<ExploreGrassState>(game));
    }
    else if(wildPokemon->isKO()) {
        cout << "You win!" << endl;
        game.transitionToState(make_unique<ExploreGrassState>(game));
    }
    else {
        wildPokemon->attack(playerParty.getActivePokemon());
        if(playerParty.getActivePokemon().isKO()) {
            game.transitionToState(make_unique<GameOverState>(game));
        }
        else {
            run();
        }
    }
}
void FightState::action1() {
    playerParty.getActivePokemon().attack(*wildPokemon);
}

void FightState::action2() {
    if(UtilityFunctions::randomEvent(0.3f)) {
    }
}

void FightState::action3() {
    cout << "You try to flee..." << endl;
    flightSuccess = UtilityFunctions::randomEvent(0.5f);
    if (flightSuccess){
        cout << "You flee succesfully!" << endl;
    }
    else {
        cout << "You fail to flee!" << endl;
    }
}