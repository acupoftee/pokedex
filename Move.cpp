#include "Move.h"

using namespace std;

Move::Move(int level, string name, string type, string category,
		int attack, int accuracy, int pp, int effect_percent, string description) : 
	Level_(level),
	Name_(name),
	Type_(type),
	Category_(category),
	Attack_(attack),
	Accuracy_(accuracy),
	Pp_(pp),
	Effect_percent_(effect_percent),
	Description_(description)
{ }

Move::~Move() { }

// Returns the level integer
int Move::getMoveLevel() const {
	return Level_;
}

void Move::setMoveLevel(int& level) {
	Level_ = level;
}

// Returns the name of the move
string Move::getMoveName() const {
	return Name_;
}

void Move::setMoveName(string& name) {
	Name_ = name;
}

// Returns the Move type in string
string Move::getMoveType() const {
	return Type_;
}

// Sets the type of the move
void Move::setMoveType(string& type) {
	Type_ = type;
}

// Returns the move category in string
string Move::getMoveCategory() const {
	return Category_;
}

// Sets the category of the move
void Move::setMoveCategory(string& category) {
	Category_ = category;
}

// Returns the attack damage in integer
int Move::getMoveAttack() const {
	return Attack_;
}

// Sets the attack damage of the move
void Move::setMoveAttack(int& attack) {
	Attack_ = attack;
}

// Returns the accuracy of the move
int Move::getMoveAccuracy() const {
	return Accuracy_;
}

// Sets the accuracy of the move
void Move::setMoveAccuracy(int& accuracy) {
	Accuracy_ = accuracy;
}

// Returns the PP amount of the move
int Move::getMovePP() const {
	return Pp_;
}

// Sets the PP amount of the move
void Move::setMovePP(int& pp) {
	Pp_ = pp;
}

// Returns the effect percent of the move
int Move::getMoveEffectPercent() const {
	return Effect_percent_;
}

// Sets the effect percent of the move
void Move::setMoveEffectPercent(int& effectPercent) {
	Effect_percent_ = effectPercent;
}

// Returns the description of the move
string Move::getMoveDescription() const {
	return Description_;
}

// Sets the description of the move
void Move::setMoveDescription(string& description) {
	Description_ = description;
}