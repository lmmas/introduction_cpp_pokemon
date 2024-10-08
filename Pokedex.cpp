//
// Created by louismmassin on 9/12/24.
//
#include <fstream>
#include <sstream>
#include "Pokedex.h"

#include <memory>

#include "PokemonParty.h"
#include "UtilityFunctions.h"

shared_ptr<Pokedex> Pokedex::instance = nullptr;

Pokedex::Pokedex(string csvPath) {
    lireCSV(csvPath);
}

void Pokedex::lireCSV(string csvPath) {
        ifstream fichier(csvPath); // Ouvre le fichier
        if (!fichier.is_open()) { // Vérifie si le fichier est bien ouvert
            cerr << "Impossible d'ouvrir le fichier : " << csvPath << endl;
            return;
        }
        string ligne;
        int lineNumber = 0;
        while (getline(fichier, ligne)) {
            // Lit le fichier ligne par ligne
            stringstream ss(ligne); // Utilise un flux pour diviser la ligne
            string cellule;
            vector<string> donneesLigne;
            // Divise la ligne en cellules séparées par des virgules
            while (getline(ss, cellule, ',')) {
                donneesLigne.push_back(cellule); // Ajoute chaque cellule au vecteur
            }
            if(lineNumber > 0) {
                int id = stoi(donneesLigne.at(0));
                string name = donneesLigne.at(1);
                Pokemon::PokemonType type1 = Pokemon::stringToType(donneesLigne.at(2));
                Pokemon::PokemonType type2 = Pokemon::stringToType(donneesLigne.at(3));
                int hitPoints = stoi(donneesLigne.at(5));
                int attackStat = stoi(donneesLigne.at(6));
                int defenseStat = stoi(donneesLigne.at(7));
                int generation = stoi(donneesLigne.at(11));

                list.push_back(make_unique<Pokemon>(id, name, type1, type2, hitPoints, attackStat, defenseStat, generation));
            }
            lineNumber++;
        }
}


unique_ptr<Pokemon> Pokedex::getPokemon(int id) {
    for(const auto& pp: list) {
        if(pp->getId() == id) {
            return make_unique<Pokemon>(*pp);
        }
    }
    return make_unique<Pokemon>(*list.at(0));
}

unique_ptr<Pokemon> Pokedex::getPokemon(const string& name) {
    for(const auto& pp: list) {
        if(pp->getName() == name) {
            return make_unique<Pokemon>(*pp);
        }
    }
    return make_unique<Pokemon>(*list.at(0));
}

shared_ptr<Pokedex> Pokedex::getInstance() {
    if(instance == nullptr) {
        instance = shared_ptr<Pokedex>(new Pokedex("../resources/pokedex.csv"));
    }
    return instance;
}

unique_ptr<Pokemon> Pokedex::randomPokemon() {
    int index = UtilityFunctions::randomInt(list.size());
    return make_unique<Pokemon>(*list.at(index));
}

