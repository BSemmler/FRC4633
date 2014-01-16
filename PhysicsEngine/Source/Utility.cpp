#include "Utility.h"
#include <cmath>
#define PI 3.14159265

float Utility::CalcHypotenuse_AdjacentSideOppisiteSide(float adjacentSide, float oppisiteSide)
{
	float total = 0;
	total = adjacentSide * adjacentSide;
	total += (oppisiteSide * oppisiteSide);
	return sqrt(total);
}

float Utility::CalcHypotenuse_SineAngle(float angleAdjacent, float oppisiteSide)
{
	float total = 0;
	total = sin(angleAdjacent * PI / 180);
	return oppisiteSide / total;
}

float Utility::CalcHypotenuse_CosineAngle(float angleAdjacent, float adjacentSide)
{
	float total = 0;
	total = cos(angleAdjacent * PI / 180);
	return adjacentSide / total;
}

float Utility::DegreesToRads(float Angle)
{
	return Angle * PI / 180;
}

float Utility::RadsToDegrees(float Angle)
{
	return Angle / PI * 180;
}
