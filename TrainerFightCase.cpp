//
// Created by louismmassin on 9/17/24.
//

#include "TrainerFightCase.h"

#include "GameOverState.h"

TrainerFightCase::TrainerFightCase(Game &game): GameState(game), trainerParty(trainerPokeball){
    auto pokedex = Pokedex::getInstance();
    trainerParty.addPokemon(pokedex->getPokemon("Garchomp"));
    trainerParty.addPokemon(pokedex->getPokemon("Infernape"));
    trainerParty.addPokemon(pokedex->getPokemon("Gyarados"));
    trainerParty.addPokemon(pokedex->getPokemon("Staraptor"));
    trainerParty.addPokemon(pokedex->getPokemon("Alakazam"));
    trainerParty.addPokemon(pokedex->getPokemon("Magnezone"));
    cout << "Trainer Gauthier wants to fight!!!" << endl;
    run();
}

void TrainerFightCase::run() {
    if(playerParty.getActivePokemon().isKO()) {
        if(playerParty.allPokemonsKO()){
            game.transitionToState(make_unique<GameOverState>(game));
        }
        else {
            int selectedIndex = selectNonKOPrompt(playerParty);
            playerParty.setActivePokemon(selectedIndex);
            cout << "Go " << playerParty.getActivePokemon().getName() << "!" << endl;
        }
    }
    cout << "'1': attack; '2': change Pokemon"<< endl;
    promptAction();
    if(trainerParty.getActivePokemon().isKO()) {
        if(trainerParty.allPokemonsKO()) {
            cout << "You win the game!!!" << endl;
        }
        else {
            int randomInt = playerParty.findNONKOIndex();
            playerParty.setActivePokemon(randomInt);
            cout << "Gauthier chooses " << trainerParty.getActivePokemon().getName() << "!" << endl;
            trainerParty.getActivePokemon().attack(playerParty.getActivePokemon());
            run();
        }
    }
    else {
        trainerParty.getActivePokemon().attack(playerParty.getActivePokemon());
        run();
    }
}

void TrainerFightCase::action1() {
    playerParty.getActivePokemon().attack(trainerParty.getActivePokemon());
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