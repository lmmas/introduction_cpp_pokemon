#include "Pokemon.hpp"
	Pokemon::Pokemon(int id, 
		const std::string& name,
		int hitPoint,
		int attackStat,
		int defenseStat,
		int generation) : id(id), name(name), hitPoint(hitPoint), attackStat(attackStat), defenseStat(defenseStat), generation(generation) {
		//std::cout << "Go, " << this->name << "!" << std::endl;
		pokemonCount++;
	}

	Pokemon::Pokemon(Pokemon& otherPokemon) : id(otherPokemon.id), name(otherPokemon.name), hitPoint(otherPokemon.hitPoint), attackStat(otherPokemon.attackStat), defenseStat(otherPokemon.defenseStat), generation(otherPokemon.generation) {
		pokemonCount++;
	}
	Pokemon::~Pokemon() {
		std::cout << "Non, " << this->name << "!!" << std::endl;
		pokemonCount--;
	}

	void Pokemon::attack(Pokemon ennemyPokemon) {
		ennemyPokemon.damage(this->attackStat);
	}

	void Pokemon::damage(int ennemyAttack) {
		if (this->defenseStat < ennemyAttack) {
			this->hitPoint -= (ennemyAttack - this->defenseStat);
			if (this->hitPoint <= 0) {
				std::cout << this->name << "est KO!!!" << std::endl;
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

	void Pokemon::displayInfo() const {
		std::cout << "id: " << this->id << std::endl;
		std::cout << "name: " << this->name << std::endl;
		std::cout << "hitPoint: " << this->hitPoint << std::endl;
		std::cout << "attack: " << this->attackStat << std::endl;
		std::cout << "defense: " << this->defenseStat << std::endl;
		std::cout << "generation: " << this->generation << std::endl;
	}
