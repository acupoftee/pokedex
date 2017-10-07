#pragma once
#include <string>

using namespace std;

class Move {
private:
	int Level_; // Level requirement for the move, can be 0
	string Name_; // Name of the move
	string Type_; // Type of the move (e.g. Ground)
	string Category_; // Category of move, Other, physical, etc.
	int Attack_; // Damage of the move, can be 0
	int Accuracy_; // Accuracy of the move, max 100
	int Pp_; // Quantity for the move
	int Effect_percent_; // Effect of the move, can be 0
	string Description_; // Description of the move

public:
	Move::Move(int, string, string, string, int, int, int pp, int, string);

	Move::~Move();

	// Returns the level integer
	int getMoveLevel() const;

	// Sets the level of the move
	void setMoveLevel(int&);

	// Returns the move name in string
	string getMoveName() const;

	// Sets the name of the move
	void setMoveName(string&);

	// Returns the Move type in string
	string getMoveType() const;

	// Sets the type of the move
	void setMoveType(string&);

	// Returns the move category in string
	string getMoveCategory() const;

	void setMoveCategory(string&);

	// Returns the attack damage in integer
	int getMoveAttack() const;

	// Sets the attack damage of the move
	void setMoveAttack(int&);

	// Returns the accuracy of the move
	int getMoveAccuracy() const;

	// Sets the accuracy of the move
	void setMoveAccuracy(int&);

	// Returns the PP amount of the move
	int getMovePP() const;

	// Sets the PP amount of the move
	void setMovePP(int&);

	// Returns the effect percent of the move
	int getMoveEffectPercent() const;

	// Sets the effect percent of the move
	void setMoveEffectPercent(int&);

	// Returns the description of the move
	string getMoveDescription() const;

	// Sets the description of the move
	void setMoveDescription(string&);
};