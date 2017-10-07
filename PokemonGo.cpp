#include "PokemonGo.h"
#include <iostream>
#include <limits>

// Default Constructor
//
// The default constructor is being overloaded together with the parent
// class
PokemonGo::PokemonGo(string nickname, int cp, int hp, int stardust, int level, int stamina,
	Pokemon& pokemon) :
	Pokemon(pokemon),
	nickname_(nickname),
	cp_(cp),
	hp_(hp),
	stardust_(stardust),
	level_(level),
	stamina_(stamina) { }

// Destruction
PokemonGo::~PokemonGo() {};

 bool PokemonGo::calculatePotential(LevelData& levelData) const {
	std::cout << "Candy required for the level: " << levelData.getCandy() << std::endl;
	std::cout << "Stardust required for the level: " << levelData.getDust() << std::endl;

	// Reference Formulas
	// CP = (Base Atk + Atk IV) * (Base Def + Def IV)0.5 * (Base Stam + Stam IV)0.5 * Lvl(CPScalar)2 / 10
	// HP = (Base Stam + Stam IV) * Lvl(CPScalar)
	// CP = (Base Atk + Atk IV) * (Base Def + Def IV) ^ 0.5 * (Base Stam + Stam IV) ^ 0.5 * Lvl(CPScalar) ^ 2 / 10
	
	// Calculate the CP IV
	int cpIV = (stamina_ * levelData.getCpScalar()) * 0.5 * cp_ / 10 * level_;

	// Print it out
	std::cout << nickname_ << "'s CP IV is: " << cpIV << std::endl;

	// http://stackoverflow.com/questions/903221/press-enter-to-continue
	std::cout << "Type any key and enter to Continue";
	if (std::cin.get())
	return true;
}

int PokemonGo::getLevel() const {
	return level_;
}