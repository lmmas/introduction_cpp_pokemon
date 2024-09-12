#include <vector>
#include "Pokemon.hpp"
class SetOfPokemon{
protected:
	std::vector<Pokemon*> list;
public:
	SetOfPokemon();
	virtual Pokemon getPokemon(std::string name) = 0;
	virtual Pokemon getPokemon(int id) = 0;
	void displayList();
};