#pragma once
class Utility
{
public:
	float CalcHypotenuse_AdjacentSideOppisiteSide(float adjacentSide, float oppisiteSide);
	float CalcHypotenuse_SineAngle(float angleAdjacent, float oppisiteSide);
	float CalcHypotenuse_CosineAngle(float angleAdjacent, float adjacentSide);
	float DegreesToRads(float Angle);
	float RadsToDegrees(float Angle);
}; 
