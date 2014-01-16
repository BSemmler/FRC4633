#pragma once
namespace Physics
{
	class PhysicsClass
	{
	public:
		float Force(float mass, float acceleration); // Input mass, acceleration
		
		float Friction(float forceNormal, float frictionCoefficiant);
		
		float Drag(float fluidDensity, float velocity, float crossSectionSA, float dragCoefficiant);
		
		float CalculateTrajectory(float force, float mass, float drag, float Angle);
		
		float CalcVelocity(float distance, float time); // Inpute Distance, Time
		
		float CalcAcceleration(float netForce, float mass); // Input  Net Force, Mass  ||  Velocity, Time
	};
}
