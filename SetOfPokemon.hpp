#pragma once
#include <memory>
#include <vector>
#include "Pokemon.hpp"

using namespace std;
class SetOfPokemon{
protected:
	vector<unique_ptr<Pokemon>> list;
public:
	SetOfPokemon() = default;
	virtual unique_ptr<Pokemon> getPokemon(std::string name) = 0;
	virtual unique_ptr<Pokemon> getPokemon(int id) = 0;
	void displayList();
};