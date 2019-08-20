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

float SteeringBehavior::CalculateOrientation(float currentOrientation, Vector2f currentVelocity)
{
	if (currentVelocity.length() > 0)
	{
		return atan2(-currentVelocity.x, -currentVelocity.y);
	}
	else
	{
		return currentOrientation;
	}
}

Vector2f SteeringBehavior::Seek(Entity* target)
{
	Vector2f result;
	result = target->GetPosition() - m_owner->GetPosition();
	result.normalize();
	result *= MAX_SPEED;

	m_orientation = CalculateOrientation(m_orientation, result);

	return result;
}

Vector2f SteeringBehavior::Flee(Entity* target)
{
	Vector2f result;
	result = m_owner->GetPosition() - target->GetPosition();
	result.normalize();
	result *= MAX_SPEED;

	m_orientation = CalculateOrientation(m_orientation, result);

	return result;
}

Vector2f SteeringBehavior::Arrive(Entity* target)
{
	Vector2f result;
	float radius = 2.0f;
	float timeToTarget = 0.25f;

	result = target->GetPosition() - m_owner->GetPosition();
	if (result.length() < radius)
	{
		return Vector2f(0.0f, 0.0f);
	}

	result /= timeToTarget;
	if (result.length() > MAX_SPEED)
	{
		result.normalize();
		result *= MAX_SPEED;
	}

	m_orientation = CalculateOrientation(m_orientation, result);

	return result;
}

Vector2f SteeringBehavior::Wander(Entity* target)
{
	Vector2f result;

	//result = MAX_SPEED * m_orientation;

	return result;
}
