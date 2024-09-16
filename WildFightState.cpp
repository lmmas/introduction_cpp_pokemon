//
// Created by louismmassin on 9/12/24.
//

#include "WildFightState.h"

#include "ExploreGrassState.h"
#include "GameOverState.h"
#include "UtilityFunctions.h"


WildFightState::WildFightState(Game& game): GameState(game) {
    wildPokemon = Pokedex::getInstance()->randomPokemon();
    cout << "A wild " << wildPokemon->getName() << " appears!" << endl;
    cout << "Go " << playerParty.getActivePokemon().getName() << "!" << endl;
}

void WildFightState::run() {
    cout << "'1': attack; '2': throw Pokeball; '3': flee" << endl;
    promptAction();
    if(flightSuccess) {
        game.transitionToState(make_unique<ExploreGrassState>(game));
    }
    else if(catchSuccess) {
        wildPokemon->restore();
        playerPokeball.addPokemon(std::move(wildPokemon));
        game.transitionToState(make_unique<ExploreGrassState>(game));
    }
    else if(wildPokemon->isKO()) {
        cout << "You win!" << endl;
        game.transitionToState(make_unique<ExploreGrassState>(game));
    }
    else {
        wildPokemon->attack(playerParty.getActivePokemon(), playerParty.getActivePokemon().getAttackType());
        if(playerParty.getActivePokemon().isKO()) {
            game.transitionToState(make_unique<GameOverState>(game));
        }
        else {
            run();
        }
    }
}
void WildFightState::action1() {
    playerParty.getActivePokemon().attack(*wildPokemon, wildPokemon->getAttackType());
}

void WildFightState::action2() {
    cout << "Throwing a Pokeball!" << endl;
    catchSuccess = UtilityFunctions::randomEvent(0.3f);
    sleep(1);
    if(catchSuccess) {
        cout << "Caught!" << endl;
    }
    else {
        cout << "Capture failed!" << endl;
    }
}

void WildFightState::action3() {
    cout << "You try to flee..." << endl;
    flightSuccess = UtilityFunctions::randomEvent(0.5f);
    if (flightSuccess){
        cout << "You flee succesfully!" << endl;
    }
    else {
        cout << "You fail to flee!" << endl;
    }
}