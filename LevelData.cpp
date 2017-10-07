#include "LevelData.h"

int LevelData::getDust() const
{
	return dust_;
}

float LevelData::getCpScalar() const
{
	return cpScalar_;
}

int LevelData::getCandy() const
{
	return candy_;
}

LevelData::LevelData(int level, int dust, int candy, float cpScalar) :
	level_(level),
	dust_(dust),
	candy_(candy),
	cpScalar_(cpScalar)
{}

LevelData::~LevelData() {};
