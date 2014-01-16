#include "Physics.h"

float Physics::PhysicsClass::fForce(float mass, float acceleration)
{
	return mass * acceleration;
}

float Physics::PhysicsClass::Friction(float force, float frictionCoefficiant, float forceNormal)
{
	return force * frictionCoefficiant;
}

float Physics::PhysicsClass::Drag(float fluidDensity, float velocity, float crossSectionSA, float dragCoefficiant)
{
	return (fluidDensity * (velocity * velocity) * dragCoefficiant * crossSectionSA / 2);
}

float Physics::PhysicsClass::CalculateTrajectory(float force, float mass, float drag, float angle)
{
	return 0;
}

float Physics::PhysicsClass::CalcVelocity(float distance, float time)
{
	return distance / time;
}

float Physics::PhysicsClass::CalcAcceleration(float netForce, float mass)
{
	return netForce / mass;
}
