#include "SteeringBehavior.h"
#include "Entity.h"

SteeringBehavior::SteeringBehavior(Entity* owner)
	: m_owner(owner)
{
	m_position = Vector2f(0.0f, 0.0f);
	m_velocity = Vector2f(0.0f, 0.0f);
	m_acceleration = Vector2f(0.0f, 0.0f);
	m_orientation = 0.0f;
	m_rotation = 0.0f;
}

SteeringBehavior::~SteeringBehavior()
{

}

void SteeringBehavior::Update(float deltaTime)
{
	m_position += m_velocity * deltaTime;
	m_orientation += m_rotation * deltaTime;

	m_velocity += m_acceleration * deltaTime;
	m_rotation += m_acceleration.length() * deltaTime;
}

void SteeringBehavior::SetPosition(Vector2f position)
{
	m_position = position;
}

void SteeringBehavior::SetVelocity(Vector2f velcoity)
{
	m_velocity = velcoity;
}

void SteeringBehavior::SetAcceleration(Vector2f accel)
{
	m_acceleration = accel;
}

void SteeringBehavior::SetOrientation(float orientation)
{
	m_orientation = orientation;
}

void SteeringBehavior::SetRotation(float rotation)
{
	m_rotation = rotation;
}
