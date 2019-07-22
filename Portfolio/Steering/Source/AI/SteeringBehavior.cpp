#include "SteeringBehavior.h"
#include "Entity.h"

SteeringBehavior::SteeringBehavior(Entity* owner)
	: m_owner(owner)
{

}

SteeringBehavior::~SteeringBehavior()
{

}

void SteeringBehavior::Update(float deltaTime)
{

}

void SteeringBehavior::SetAcceleration(Vector2f accel)
{
	m_acceleration = accel;
}

void SteeringBehavior::SetForce(float force)
{
	m_force = force;
}

void SteeringBehavior::SetAngle(float angle)
{
	m_angle = angle;
}
