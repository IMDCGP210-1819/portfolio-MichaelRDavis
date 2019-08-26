#pragma once

#include "Math.h"
#include <memory>
#include <vmath.h>

class Entity;

float constexpr MAX_SPEED{ 1.5f };

class SteeringBehavior
{
public:
	SteeringBehavior(Entity* owner);
	~SteeringBehavior();

	void Update(float deltaTime);

	void SetPosition(Vector2f position);
	void SetVelocity(Vector2f velocity);
	void SetAcceleration(Vector2f accel);
	void SetOrientation(float orientation);
	void SetRotation(float rotation);

	float CalculateOrientation(float currentOrientation, Vector2f currentVelocity);

	Vector2f Seek(Vector2f target);
	Vector2f Flee(Vector2f target);
	Vector2f Arrive(Vector2f target);
	Vector2f Wander(Vector2f target);

	inline Vector2f GetPosition() const 
	{
		return m_position;
	}

	inline Vector2f GetVelocity() const
	{
		return m_velocity;
	}

	inline Vector2f GetAcceleration() const
	{
		return m_acceleration;
	}

	inline float GetOrientation() const
	{
		return m_orientation;
	}

	inline float GetRotation() const
	{
		return m_rotation;
	}

private:
	std::unique_ptr<Entity> m_owner;

	Vector2f m_position;
	Vector2f m_velocity;
	Vector2f m_acceleration;
	float m_orientation;
	float m_rotation;
};