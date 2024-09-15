#include "Pokemon.hpp"

#include <utility>
	Pokemon::Pokemon(int id,
		std::string  name,
		int hitPoints,
		int attackStat,
		int defenseStat,
		int generation) : id(id), name(std::move(name)), hitPoints(hitPoints), maxHP(hitPoints), attackStat(attackStat), defenseStat(defenseStat), generation(generation), ko(false){

		pokemonCount++;
	}

	Pokemon::Pokemon(const Pokemon& otherPokemon) : id(otherPokemon.id), name(otherPokemon.name), hitPoints(otherPokemon.hitPoints), maxHP(otherPokemon.maxHP), attackStat(otherPokemon.attackStat), defenseStat(otherPokemon.defenseStat), generation(otherPokemon.generation), ko(otherPokemon.ko) {
		pokemonCount++;
	}
	Pokemon::~Pokemon() {

		//std::cout << "Non, " << this->name << "!!" << std::endl;
		pokemonCount--;
	}

	void Pokemon::attack(Pokemon& ennemyPokemon) {
		cout << this->getName() << " attacks " << ennemyPokemon.getName() << "!" << endl;
		ennemyPokemon.damage(this->attackStat);
	}

	void Pokemon::damage(int ennemyAttack) {
		if (this->defenseStat < ennemyAttack) {
			this->hitPoints -= (ennemyAttack - this->defenseStat);
			if (this->hitPoints <= 0) {
				this-> hitPoints = 0;
				this->ko = true;
				cout << this->name << " is KO!!!" << endl;
			}
		}
	}

	int Pokemon::pokemonCount = 0;

	int Pokemon::getId() {
		return id;
	}

	const std::string Pokemon::getName() {
		return name;
	}

bool Pokemon::isKO() {
	return ko;
}


	void Pokemon::displayInfo() const {
		cout << "id: " << this->id << endl;
		cout << "name: " << this->name << endl;
		cout << "hitPoint: " << this->hitPoints << endl;
		cout << "attack: " << this->attackStat << endl;
		cout << "defense: " << this->defenseStat << endl;
		cout << "generation: " << this->generation << endl;
	}
