#pragma once

#include <iostream>
#include <string>
using namespace std;
	class Pokemon {
	private:
		int id;
		const string name;
		int hitPoints;
		int maxHP;
		int attackStat;
		int defenseStat;
		int generation;
		bool ko;
	public:
		static int pokemonCount ;
		Pokemon(int id,
			string name,
			int hitPoints,
			int attackStat,
			int defense,
			int generation);
		Pokemon(const Pokemon& otherPokemon);
		~Pokemon();

		int getId();
		const string getName();
		bool isKO();
		void displayInfo() const;
		void damage(int);
		void attack(Pokemon&);
	};
