#pragma once

#include "Math.h"
#include <memory>
#include <vmath.h>

class Entity;

float constexpr MAX_SPEED{ 0.1f };

class SteeringBehavior
{
public:
	SteeringBehavior(Entity* owner);
	~SteeringBehavior();

	void Update(float deltaTime);

	void SetAcceleration(Vector2f accel);
	void SetForce(float force);
	void SetAngle(float angle);

	inline Vector2f GetAcceleration() const
	{
		return m_acceleration;
	}

	inline float GetForce() const
	{
		return m_force;
	}

	inline float GetAngle() const
	{
		return m_angle;
	}

private:
	std::unique_ptr<Entity> m_owner;

	Vector2f m_acceleration;
	float m_force;
	float m_angle;
};