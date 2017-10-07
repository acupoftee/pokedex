#include "Pokemon.h"
#include <iostream>

using namespace std;

// http://stackoverflow.com/questions/6281461/enum-to-string-c
static const char * TypeStrings[] = {
	"BUG", // 0 
	"GRASS", // 1
	"DARK", // 2
	"GROUND", // 3
	"DRAGON", // 4
	"ICE", // 5
	"ELECTRIC", // 6
	"NORMAL", // 7
	"FAIRY", // 8
	"POISON", // 9
	"FIGHTING", // 10
	"PSYCHIC", // 11
	"FIRE", // 12
	"ROCK", // 13
	"FLYING", // 14
	"STEEL", // 15
	"GHOST", // 16
	"WATER" // 17
};

Pokemon::Pokemon(int index, string name, vector<Evolution> evolutions, vector<Type> types, vector<Move> moves) :
	index_(index),
	name_(name),
	evolutions_(evolutions),
	types_(types),
	moves_(moves)
{}

Pokemon::~Pokemon()
{
}

vector<const char*> Pokemon::getTypesInString() {
	vector<const char*> result;

	for (const char * c : TypeStrings) {
		result.push_back(c);
	}

	return result;
}

int Pokemon::getPokemonId() const {
	return index_;
}

string Pokemon::getPokemonName() const {
	return name_;
}

void Pokemon::setPokemonName(string& name) {
	name_ = name;
}

int Pokemon::getTypesSize() const {
	return types_.size();
}

bool Pokemon::operator==(const Pokemon& pokemon) const {
	return index_ == pokemon.index_;
}

bool Pokemon::contains(const string& name) const {
	// Let us have temporary variables to convert them to lowercase
	string currName = name_;
	string compName = name;

	// We now convert them to lower first
	std::transform(currName.begin(), currName.end(), currName.begin(), ::tolower);
	std::transform(compName.begin(), compName.end(), compName.begin(), ::tolower);

	if (strstr(currName.c_str(), compName.c_str()))
	{
		return true;
	}

	return false;
}

vector<Evolution> Pokemon::getEvolutions() const {
	return evolutions_;
}

vector<Evolution>& Pokemon::getExactEvolutions() {
	return evolutions_;
}

vector<Pokemon::Type> Pokemon::getTypesVector() const {
	return types_;
}

const char * GetStringType(int enumVal)
{
	return TypeStrings[enumVal];
}

vector<string> Pokemon::typesToString() {
	vector<string> result;

	for (Type t : types_) {
		result.push_back(GetStringType(t));
	}

	return result;
}

// Compared to typesToString, we're reducing the function into
// a Linear Incremental Difficulty O(N) Function instead of 
// an exponentially difficult (O2N) function
vector<int> Pokemon::typesToInt() const {
	vector<int> result;

	for (Type t : types_) {
		result.push_back(static_cast<int>(t));
	}

	return result;
}

int Pokemon::typeToInt(const Type& t) const {
	return static_cast<int>(t);
}

vector<Move> Pokemon::getMoves() const {
	return moves_;
}

vector<Move>& Pokemon::getExactMoves() {
	return moves_;
}

// couts a list of Enumerators for the user to cin via enumIntToString()
// Checks the input, and eventually returns a string
void Pokemon::printEnumChoices() {
	for (int i = Type::BUG; i < Type::WATER + 1; ++i) {
		switch (i) {
		case Type::BUG: // 0
			cout << "(1) Bug" << std::endl;
			break;
		case Type::GRASS: // 1
			cout << "(2) Grass" << std::endl;
			break;
		case Type::DARK: // 2
			cout << "(3) Dark" << std::endl;
			break;
		case Type::GROUND: // 3
			cout << "(4) Ground" << std::endl;
			break;
		case Type::DRAGON: // 4
			cout << "(5) Dragon" << std::endl;
			break;
		case Type::ICE: // 5
			cout << "(6) Ice" << std::endl;
			break;
		case Type::ELECTRIC: // 6
			cout << "(7) Electric" << std::endl;
			break;
		case Type::NORMAL: // 7
			cout << "(8) Normal" << std::endl;
			break;
		case Type::FAIRY: // 8
			cout << "(9) Fairy" << std::endl;
			break;
		case Type::POISON: // 9
			cout << "(10) Poison" << std::endl;
			break;
		case Type::FIGHTING: // 10
			cout << "(11) Fighting" << std::endl;
			break;
		case Type::PSYCHIC: // 11
			cout << "(12) Psychic" << std::endl;
			break;
		case Type::FIRE: // 12
			cout << "(13) Fire" << std::endl;
			break;
		case Type::ROCK: // 13
			cout << "(14) Rock" << std::endl;
			break;
		case Type::FLYING: // 14
			cout << "(15) Flying" << std::endl;
			break;
		case Type::STEEL: // 15
			cout << "(16) Steel" << std::endl;
			break;
		case Type::GHOST: // 16
			cout << "(17) Ghost" << std::endl;
			break;
		case Type::WATER: // 17
			cout << "(18) Water" << std::endl;
			break;
		default:
			cout << "Failed to parse a Type enum." << std::endl;
			break;
		}
	}
}

// Returns the string of the Enumerator identified by an Integer
Pokemon::Type Pokemon::enumIntToType(int inType) {
	return Type(inType); // http://www.gamedev.net/topic/330476-cc-how-to-convert-int-to-enum/
}

vector<Pokemon::Type> Pokemon::stringToTypes(vector<string>& typesInString) {
	vector<Type> types;

	for (string type : typesInString) {
		Type t;

		// Let's reduce if statement filtering with chars
		// http://www.cplusplus.com/reference/string/string/at/
		switch (type.at(0)) {
		case 'b':
			t = Type::BUG;
			break;
		case 'd':
			if (type == "dark") {
				t = Type::DARK;
			}
			else if (type == "dragon") {
				t = Type::DRAGON;
			}
			break;
		case 'e':
			if (type == "electric") {
				t = Type::ELECTRIC;
			}
			break;
		case 'f':
			if (type == "fairy") {
				t = Type::FAIRY;
			}
			else if (type == "fighting") {
				t = Type::FIGHTING;
			}
			else if (type == "fire") {
				t = Type::FIRE;
			}
			else if (type == "flying") {
				t = Type::FLYING;
			}
			break;
		case 'g':
			if (type == "ghost") {
				t = Type::GHOST;
			}
			else if (type == "grass") {
				t = Type::GRASS;
			}
			else if (type == "ground") {
				t = Type::GROUND;
			}
			break;
		case 'i':
			if (type == "ice") {
				t = Type::ICE;
			}
			break;
		case 'n':
			if (type == "normal") {
				t = Type::NORMAL;
			}
			break;
		case 'p':
			if (type == "poison") {
				t = Type::POISON;
			}
			else if (type == "psychic") {
				t = Type::PSYCHIC;
			}
			break;
		case 'r':
			if (type == "rock") {
				t = Type::ROCK;
			}
			break;
		case 's':
			if (type == "steel") {
				t = Type::STEEL;
			}
			break;
		case 'w':
			if (type == "water") {
				t = Type::WATER;
			}
			break;
		default:
			cout << "Error detecting type for: " + type << std::endl;
			break;
		}

		types.push_back(t); // Push back the enum
	}

	return types;
}

ostream & operator<<(ostream& ostreamObj, const Pokemon& pokemon)
{
	ostreamObj << pokemon.getPokemonName();

	return ostreamObj;
}

istream & operator >> (istream& istreamObj, const Pokemon& pokemon) {
	return istreamObj;
}