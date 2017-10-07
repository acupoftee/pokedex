#pragma once

// Based on https://github.com/andromedado/pokemon-go-iv-calculator/blob/master/support/levelUpData.js
class LevelData {
private:
	int level_;
	int dust_;
	int candy_;
	float cpScalar_;

public:
	// Retrieves the Stardust requirement
	int getDust() const;

	// Retrieves the cpScalar
	float getCpScalar() const;

	// Retrieves the amount of candy required.
	int getCandy() const;

	// Default Constructor
	LevelData(int, int, int, float); // Not giving in default values to prevent calculation errors

	// Destructor
	~LevelData();
};