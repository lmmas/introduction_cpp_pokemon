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
    cout << "'1': attack; '2': change Pokemon; '3': throw Pokeball; '4': flee" << endl;
    promptAction();
    if(flightSuccess) {
        game.transitionToState(make_unique<ExploreGrassState>(game));
    }
    else if(catchSuccess) {
        wildPokemon->restore();
        if(playerParty.getList().size() < PokemonParty::partySize) {
            cout << wildPokemon->getName() << " has been added to your party!" << endl;
            playerParty.addPokemon(std::move(wildPokemon));
        }
        else {
            cout << wildPokemon->getName() << " has been transfered to PC!" << endl;
            playerPokeball.addPokemon(std::move(wildPokemon));
        }
        game.transitionToState(make_unique<ExploreGrassState>(game));
    }
    else if(wildPokemon->isKO()) {
        cout << "You win!" << endl;
        game.transitionToState(make_unique<ExploreGrassState>(game));
    }
    else {
        wildPokemon->attack(playerParty.getActivePokemon());
        if(playerParty.getActivePokemon().isKO()) {
            if(playerParty.allPokemonsKO()){
                game.transitionToState(make_unique<GameOverState>(game));
            }
            else {
                int selectedIndex = selectNonKOPrompt(playerParty);
                playerParty.setActivePokemon(selectedIndex);
                cout << "Go " << playerParty.getActivePokemon().getName() << "!" << endl;
                run();
            }
        }
        else {
            run();
        }
    }
}
void WildFightState::action1() {
    playerParty.getActivePokemon().attack(*wildPokemon);
}

void WildFightState::action2() {
    cout << "Select Pokemon for fighting:" << endl;
    playerParty.displayList();
    int activeIndex = selectFromListPrompt(playerParty.getList().size());
    playerParty.setActivePokemon(activeIndex);
    cout << "Go " << playerParty.getActivePokemon().getName() << "!" << endl;
    cout << "'1': attack; '2': change Pokemon; '3': throw Pokeball; '4': flee" << endl;
    promptAction();
}

void WildFightState::action3() {
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

void WildFightState::action4() {
    cout << "You try to flee..." << endl;
    flightSuccess = UtilityFunctions::randomEvent(0.5f);
    sleep(1);
    if (flightSuccess){
        cout << "You flee succesfully!" << endl;
    }
    else {
        cout << "You fail to flee!" << endl;
    }
}

void WildFightState::action5() {

}

void WildFightState::action6() {
}
