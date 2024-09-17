//
// Created by louismmassin on 9/17/24.
//

#include "TrainerFightCase.h"

TrainerFightCase::TrainerFightCase(Game &game): GameState(game){
    playerParty.getPokemon("Garchomp");
    playerParty.getPokemon("Infernape");
    playerParty.getPokemon("Gyarados");
    playerParty.getPokemon("Staraptor");
    playerParty.getPokemon("Alakazam");
    playerParty.getPokemon("Magnezone");
    cout << "Trainer Gauthier wants to fight!!!" << endl;
    promptAction();
}

void TrainerFightCase::run() {
    cout << "'1': attack; '2': change Pokemon"<< endl;
    promptAction();
    if(trainerParty.getActivePokemon().isKO()) {
        if(trainerParty.allPokemonsKO()) {
            cout << "You win the game!!!" << endl;
        }
        else {
            int randomInt = playerParty.findNONKOIndex();
            playerParty.setActivePokemon(randomInt);
        }
    }
    else {
        run();
    }
}

void TrainerFightCase::action1() {
    playerParty.getActivePokemon().attack(trainerParty.getActivePokemon(), trainerParty.getActivePokemon().getAttackType());
}

void TrainerFightCase::action2() {
    cout << "Select Pokemon for fighting:" << endl;
    playerParty.displayList();
    int activeIndex = selectFromListPrompt(playerParty.getList().size());
    playerParty.setActivePokemon(activeIndex);
    cout << "Go " << playerParty.getActivePokemon().getName() << "!" << endl;
    cout << "'1': attack; '2': change Pokemon; '3': throw Pokeball; '4': flee" << endl;
    promptAction();
}

void TrainerFightCase::action3() {
    invalidKey();
}

void TrainerFightCase::action4() {
    invalidKey();
}

void TrainerFightCase::action5() {
    invalidKey();
}

void TrainerFightCase::action6() {
    invalidKey();
}