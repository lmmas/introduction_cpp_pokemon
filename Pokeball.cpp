//
// Created by louismmassin on 9/12/24.
//

#include "Pokeball.h"

unique_ptr<Pokemon> Pokeball::getPokemon(int id) {
    for(int i = 0; i < list.size(); i++) {
        if(list.at(i)->getId() == id) {
            unique_ptr<Pokemon> pp = std::move(list.at(i));
            list.erase(list.begin()+i);
            return pp;
        }
    }
    return nullptr;
}

unique_ptr<Pokemon> Pokeball::getPokemon(std::string name) {
    for(int i = 0; i < list.size(); i++) {
        if(list.at(i)->getName() == name) {
            unique_ptr<Pokemon> pp = std::move(list.at(i));
            list.erase(list.begin()+i);
            return pp;
        }
    }
    return nullptr;
}