#include "Pokemon.hpp"

#include <utility>
	Pokemon::Pokemon(int id,
		std::string  name,
		PokemonType type1,
		PokemonType type2,
		int hitPoints,
		int attackStat,
		int defenseStat,
		int generation) : id(id), name(std::move(name)), type1(type1), type2(type2), hitPoints(hitPoints), maxHP(hitPoints), attackStat(attackStat), defenseStat(defenseStat), generation(generation), ko(false){
		pokemonCount++;
	}

	Pokemon::Pokemon(const Pokemon& otherPokemon) : id(otherPokemon.id), name(otherPokemon.name), type1(otherPokemon.type1), type2(otherPokemon.type2), hitPoints(otherPokemon.hitPoints), maxHP(otherPokemon.maxHP), attackStat(otherPokemon.attackStat), defenseStat(otherPokemon.defenseStat), generation(otherPokemon.generation), ko(otherPokemon.ko) {
		pokemonCount++;
	}
	Pokemon::~Pokemon() {

		//std::cout << "Non, " << this->name << "!!" << std::endl;
		pokemonCount--;
	}

map<pair<Pokemon::PokemonType, Pokemon::PokemonType>, float> Pokemon::typeMap = {{make_pair(NORMAL, ROCK),0.5f},
{make_pair(NORMAL, GHOST),0.0f},
{make_pair(NORMAL, STEEL),0.5f},
{make_pair(NORMAL, ROCK),0.5f},
{make_pair(FIRE, FIRE),0.5f},
{make_pair(FIRE, WATER),0.5f},
{make_pair(FIRE, GRASS),2.0f},
{make_pair(FIRE, ICE),2.0f},
{make_pair(FIRE, BUG),2.0f},
{make_pair(FIRE, ROCK),2.0f},
{make_pair(FIRE, DRAGON),0.5f},
{make_pair(FIRE, STEEL),2.0f},
{make_pair(WATER, FIRE),2.0f},
{make_pair(WATER, WATER),0.5f},
{make_pair(WATER, GRASS),0.5f},
{make_pair(WATER, GROUND),2.0f},
{make_pair(WATER, ROCK),2.0f},
{make_pair(WATER, DRAGON),0.5f},
{make_pair(ELECTRIC, WATER),2.0f},
{make_pair(ELECTRIC, ELECTRIC),0.5f},
{make_pair(ELECTRIC, GRASS),0.5f},
{make_pair(ELECTRIC, GROUND),0.0f},
{make_pair(ELECTRIC, FLYING),2.0f},
{make_pair(ELECTRIC, DRAGON),0.5f},
{make_pair(GRASS, FIRE),0.5f},
{make_pair(GRASS, GRASS),2.0f},
{make_pair(GRASS, POISON),0.5f},
{make_pair(GRASS, GROUND),2.0f},
{make_pair(GRASS, FLYING),0.5f},
{make_pair(GRASS, BUG),0.5f},
{make_pair(GRASS, ROCK),2.0f},
{make_pair(GRASS, DRAGON),0.5f},
{make_pair(GRASS, STEEL),0.5f},
{make_pair(ICE, FIRE),0.5f},
{make_pair(ICE, WATER),0.5f},
{make_pair(ICE, GRASS),2.0f},
{make_pair(ICE, ICE),0.5f},
{make_pair(ICE, GROUND),2.0f},
{make_pair(ICE, FLYING),2.0f},
{make_pair(ICE, DRAGON),2.0f},
{make_pair(ICE, STEEL),0.5f},
{make_pair(FIGHTING, NORMAL),2.0f},
{make_pair(FIGHTING, ICE),2.0f},
{make_pair(FIGHTING, POISON),0.5f},
{make_pair(FIGHTING, FLYING),0.5f},
{make_pair(FIGHTING, FLYING),0.5f},
{make_pair(FIGHTING, PSYCHIC),0.5f},
{make_pair(FIGHTING, BUG),0.5f},
{make_pair(FIGHTING, ROCK),2.0f},
{make_pair(FIGHTING, GHOST),0.0f},
{make_pair(FIGHTING, DARK),2.0f},
{make_pair(FIGHTING, STEEL),2.0f},
{make_pair(FIGHTING, FAIRY),0.5f},
{make_pair(POISON, GRASS),2.0f},
{make_pair(POISON, POISON),0.5f},
{make_pair(POISON, GROUND),0.5f},
{make_pair(POISON, ROCK),0.5f},
{make_pair(POISON, GHOST),0.5f},
{make_pair(POISON, POISON),0.0f},
{make_pair(POISON, FAIRY),2.0f},
{make_pair(GROUND, FIRE),2.0f},
{make_pair(GROUND, ELECTRIC),2.0f},
{make_pair(GROUND, GRASS),0.5f},
{make_pair(GROUND, POISON),2.0f},
{make_pair(GROUND, FLYING),0.0f},
{make_pair(GROUND, BUG),0.5f},
{make_pair(GROUND, ROCK),2.0f},
{make_pair(GROUND, BUG),0.5f},
{make_pair(GROUND, STEEL),2.0f},
{make_pair(FLYING, ELECTRIC),0.5f},
{make_pair(FLYING, ELECTRIC),0.5f},
{make_pair(FLYING, GRASS),2.0f},
{make_pair(FLYING, FIGHTING),2.0f},
{make_pair(FLYING, BUG),2.0f},
{make_pair(FLYING, ROCK),0.5f},
{make_pair(FLYING, STEEL),0.5f},
{make_pair(FLYING, ELECTRIC),0.5f},
{make_pair(FLYING, GRASS),2.0f},
{make_pair(FLYING, FIGHTING),2.0f},
{make_pair(FLYING, BUG),2.0f},
{make_pair(FLYING, ROCK),0.5f},
{make_pair(FLYING, STEEL),0.5f},
{make_pair(FLYING, ELECTRIC),0.5f},
{make_pair(PSYCHIC, FIGHTING),2.0f},
{make_pair(PSYCHIC, POISON),2.0f},
{make_pair(PSYCHIC, PSYCHIC),0.5f},
{make_pair(PSYCHIC, DARK),0.0f},
{make_pair(PSYCHIC, STEEL),0.5f},
{make_pair(BUG, FIRE),0.5f},
{make_pair(BUG, GRASS),2.0f},
{make_pair(BUG, FIGHTING),0.5f},
{make_pair(BUG, POISON),0.5f},
{make_pair(BUG, FLYING),0.5f},
{make_pair(BUG, PSYCHIC),2.0f},
{make_pair(BUG, GHOST),0.5f},
{make_pair(BUG, DARK),2.0f},
{make_pair(BUG, STEEL),0.5f},
{make_pair(BUG, FAIRY),0.5f},
{make_pair(ROCK, FIRE),2.0f},
{make_pair(ROCK, ICE),2.0f},
{make_pair(ROCK, FIGHTING),0.5f},
{make_pair(ROCK, GROUND),0.5f},
{make_pair(ROCK, FLYING),2.0f},
{make_pair(ROCK, BUG),2.0f},
{make_pair(ROCK, STEEL),0.5f},
{make_pair(GHOST, NORMAL),0.0f},
{make_pair(GHOST, PSYCHIC),2.0f},
{make_pair(GHOST, GHOST),2.0f},
{make_pair(GHOST, DARK),0.5f},
{make_pair(DRAGON, DRAGON),2.0f},
{make_pair(DRAGON, STEEL),0.5f},
{make_pair(DRAGON, FAIRY),0.0f},
{make_pair(DARK, FIGHTING),0.5f},
{make_pair(DARK, PSYCHIC),2.0f},
{make_pair(DARK, GHOST),2.0f},
{make_pair(DARK, DARK),0.5f},
{make_pair(DARK, FAIRY),0.5f},
{make_pair(STEEL, FIRE),0.5f},
{make_pair(STEEL, WATER),0.5f},
{make_pair(STEEL, ELECTRIC),0.5f},
{make_pair(STEEL, ICE),2.0f},
{make_pair(STEEL, ROCK),2.0f},
{make_pair(STEEL, STEEL),0.5f},
{make_pair(STEEL, FAIRY),2.0f},
{make_pair(FAIRY, FIRE),0.5f},
{make_pair(FAIRY, POISON),2.0f},
{make_pair(FAIRY, POISON),0.5f},
{make_pair(FAIRY, DRAGON),2.0f},
{make_pair(FAIRY, DARK),2.0f},
{make_pair(FAIRY, STEEL),0.5f},
} ;

	void Pokemon::attack(Pokemon& ennemyPokemon, Pokemon::PokemonType attackType) {
		cout << this->getName() << " attacks " << ennemyPokemon.getName() << "!" << endl;
		ennemyPokemon.damage(this->attackStat, attackType);
	}

	void Pokemon::damage(int ennemyAttack, Pokemon::PokemonType attackType) {
		const int damageValue = (int)((2 * (float)averageLevel/5 + 2.0f)*averagePower*(float)ennemyAttack/(float)this->defenseStat / 50 * damageModifier(attackType, this->type1) * damageModifier(attackType, this->type2));
		cout << "damage dealt: " << damageValue << endl;
		if (damageValue >= this->hitPoints) {
			this->hitPoints = 0;
			this->ko = true;
			cout << this->name << " is KO!!!" << endl;
		}
		else {
			this->hitPoints -= damageValue;
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

Pokemon::PokemonType Pokemon::getAttackType() {
	return this->type1;
}


	void Pokemon::displayInfo() const {
		cout << "id: " << this->id << endl;
		cout << "name: " << this->name << endl;
		cout << "Type: " << this->type1 << "/" << this->type2 << endl;
		cout << "hitPoints: " << this->hitPoints << endl;
		cout << "max HP: " << this->maxHP << endl;
		cout << "attack: " << this->attackStat << endl;
		cout << "defense: " << this->defenseStat << endl;
		cout << "generation: " << this->generation << endl;
	}

float Pokemon::damageModifier(PokemonType attackType, PokemonType defenseType) {
		auto key = make_pair(attackType, defenseType);
	if(typeMap.count(key) == 1) {
		return typeMap.find(key)->second;
	}
	else {
		return 1.0f;
	}
}

Pokemon::PokemonType Pokemon::stringToType(const string &inputString) {
	static const map<string, PokemonType> conversionMap = {
		{"Normal", NORMAL},
		{"Fire", FIRE},
		{"Water", WATER},
		{"Electric", ELECTRIC},
		{"Grass", GRASS},
		{"Ice", ICE},
		{"Fighting", FIGHTING},
		{"Poison", POISON},
		{"Ground", GROUND},
		{"Flying", FLYING},
		{"Psychic", PSYCHIC},
		{"Bug", BUG},
		{"Rock", ROCK},
		{"Ghost", GHOST},
		{"Dragon", DRAGON},
		{"Dark", DARK},
		{"Steel", STEEL},
		{"Fairy", FAIRY},
		{"", NONE},
	};
		return conversionMap.find(inputString)->second;
}

void Pokemon::restore() {
	hitPoints = maxHP;
	ko = false;
}
