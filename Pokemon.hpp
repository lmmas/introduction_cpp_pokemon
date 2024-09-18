#pragma once

#include <iostream>
#include <map>
#include <string>
using namespace std;
	class Pokemon {
	public:
		enum PokemonType {
			NONE, NORMAL, FIRE, WATER, ELECTRIC, GRASS, ICE, FIGHTING, POISON, GROUND, FLYING, PSYCHIC, BUG, ROCK, GHOST, DRAGON, DARK, STEEL, FAIRY
		};
		static map<pair<PokemonType, PokemonType>,float> typeMap;
		static float damageModifier(PokemonType attackType, PokemonType defenseType);
	private:
		static const int averageLevel = 10;
		static const int averagePower = 40;
		int id;
		const string name;
		int hitPoints;
		int maxHP;
		int attackStat;
		int defenseStat;
		int generation;
		PokemonType type1;
		PokemonType type2;
		bool ko;
	public:
		static int pokemonCount ;
		Pokemon(int id,
			string name,
			PokemonType type1,
			PokemonType type2,
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
		void damage(int ennemyAttack, Pokemon::PokemonType attackType);
		void attack(Pokemon& ennemyPokemon);
		void restore();

		static PokemonType stringToType(const string& inputString);
	};
