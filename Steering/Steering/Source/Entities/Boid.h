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
	static std::vector<Boid*> m_renderables;
	sf::Vector2f m_seekTarget;

protected:
	SteeringBehaviors* m_pSteeringBehaviors;
};