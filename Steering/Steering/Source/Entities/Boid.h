#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include "Entity.h"

class SteeringBehaviors;

class Boid : public Entity
{
public:
	explicit Boid();
	explicit Boid(std::string file);
	explicit Boid(std::string file, sf::Color color);
	~Boid();

	void Update(float deltaTime) override;
	void Initialize() override;

	inline SteeringBehaviors* GetSteeringBehavior() const { return m_pSteeringBehaviors; }

public:
	float m_fleeDistance;
	float m_deacceleration;

	sf::Vector2f m_seekTarget;
	sf::Vector2f m_fleeTarget;
	sf::Vector2f m_arriveTarget;

protected:
	SteeringBehaviors* m_pSteeringBehaviors;
};