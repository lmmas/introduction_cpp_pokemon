//
// Created by louismmassin on 9/16/24.
//

#include "PokeCenterState.h"

#include "ExploreSafelyState.h"

PokeCenterState::PokeCenterState(Game& game): GameState(game) {
    cout << "Welcome to the PokeCenter!" << endl;
    cout << "All your Pokemons are healed!" << endl;
    for(const auto& pp: playerParty.getList()) {
        pp->restore();
    }
    for(const auto& pp: playerPokeball.getList()) {
        pp->restore();
    }
}

void PokeCenterState::run() {
    cout << "'1': display Pokemon party; '2': display your other Pokemons; '3': change Pokemon party; '4': back to exploration" << endl;
    promptAction();
}

void PokeCenterState::action1() {
    playerParty.displayList();
    run();
}

void PokeCenterState::action2() {
    if(!playerPokeball.getList().empty()) {
        playerPokeball.displayList();
    }
    else {
        cout << "No Pokemons" << endl;
    }
    run();
}

void PokeCenterState::action3() {
    if(!playerPokeball.getList().empty()) {
        if(playerParty.getList().size() == PokemonParty::partySize) {
            cout << "Select Pokemon in party to switch with:" << endl;
            playerParty.displayList();
            const int partyIndex = selectFromListPrompt(PokemonParty::partySize);
            cout << "Select Pokemon in pokeball:" << endl;
            playerPokeball.displayList();
            const int pokeballIndex = selectFromListPrompt(playerPokeball.getList().size());
            string pokeName = playerPokeball.getList().at(pokeballIndex)->getName();
            playerParty.switchWithPokeball(partyIndex, pokeballIndex);
            cout << "Successfully placed " << pokeName << " in slot " << partyIndex << " of party!" << endl;
        }
        else {
            cout << "Select Pokemon to add to party:" << endl;
            playerPokeball.displayList();
            const int pokeballIndex = selectFromListPrompt(playerPokeball.getList().size());
            string pokeName = playerPokeball.getList().at(pokeballIndex)->getName();
            playerParty.addPokemon(move(playerPokeball.getList().at(pokeballIndex)));
            cout << "Sucessfully added " << pokeName << " to the party!" << endl;
        }
    }
    else {
        cout << "No Pokemons" << endl;
    }
    run();
}

void PokeCenterState::action4() {
    auto anotherState = make_unique<ExploreSafelyState>(this->game);
    game.transitionToState(move(anotherState));
}

void PokeCenterState::action5() {
    invalidKey();
}

void PokeCenterState::action6() {
    invalidKey();
}
