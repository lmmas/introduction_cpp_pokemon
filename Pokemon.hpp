#pragma once
#include <iostream>
#include <string>
	class Pokemon {
	private:
		int id;
		const std::string name;
		int hitPoint;
		int attackStat;
		int defenseStat;
		int generation;
	public:
		static int pokemonCount ;
		Pokemon(int id,
			const std::string &name,
			int hitPoint,
			int attackStat,
			int defense,
			int generation);
		Pokemon(Pokemon& otherPokemon);
		~Pokemon();

		int getId();
		const std::string getName();
		void displayInfo() const;
		void damage(int);
		void attack(Pokemon);
	};
