#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <cctype> 

#include "Evolution.h"
#include "Move.h"

using namespace std;

class Pokemon
{
	//Overload the stream insertion and extraction operators
	friend ostream& operator << (ostream&, const Pokemon &);
	friend istream& operator >> (istream&, Pokemon &);

public:
	// Has to be public for PokeDex's Accessibility
	enum Type {
		BUG, // 0 
		GRASS, // 1
		DARK, // 2
		GROUND, // 3
		DRAGON, // 4
		ICE, // 5
		ELECTRIC, // 6
		NORMAL, // 7
		FAIRY, // 8
		POISON, // 9
		FIGHTING, // 10
		PSYCHIC, // 11
		FIRE, // 12
		ROCK, // 13
		FLYING, // 14
		STEEL, // 15
		GHOST, // 16
		WATER // 17
	};

protected:
	int index_;
	string name_;
	vector<Evolution> evolutions_;
	vector<Move> moves_;
	vector<Type> types_;

public:
	// == Operator to check with the Pokemon's name
	bool operator==(const Pokemon&) const;

	// Function to check the Pokemon's name with a substring of it
	bool contains(const string&) const;

	// Returns a vector of enum Types with the vector of strings
	static vector<Type> stringToTypes(vector<string>&);

	// Returns the vector of types in string
	static vector<const char*> getTypesInString();

	// Returns int pokemon
	int getPokemonId() const;

	// Returns the vector of evolutions
	vector<Evolution> getEvolutions() const;

	// Returns the EXACT vector of evolutions
	vector<Evolution>& getExactEvolutions();

	// Returns the pokemon name
	string getPokemonName() const;

	// Sets the pokemon name
	void setPokemonName(string&);

	// Returns the pokemon name with it's id
	string getPokemonNameInt(int index) const;

	// Returns the vector of enum Types
	vector<Type> getTypesVector() const;

	// Returns the size of the Types Vector
	int getTypesSize() const;

	// Returns the types in a vector of string
	vector<string> typesToString();

	// Returns the types in a vector of int
	vector<int> typesToInt() const;

	// Returns the current Type enum to an int
	int typeToInt(const Type&) const;

	// Returns the vector of moves
	vector<Move> getMoves() const;

	// Returns the EXACT vector of moves
	vector<Move>& getExactMoves();

	// Returns us the pokemon type chosen
	static void printEnumChoices();

	// Returns us the enum in string
	static Type enumIntToType(int);

	// Sets the pokemon id to evolve to
	void setPokemonId(int Pokemon);

	// Sets the Pokemon evolution event string
	void setEvent(string Event);

	// Parameterized Constructor
	Pokemon(int, string, vector<Evolution>, vector<Type>, vector<Move>);

	// Destructor for Pokemon
	~Pokemon();

};
