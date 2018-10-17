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

public:
	static std::vector<Boid*> m_renderables;

protected:
	SteeringBehaviors* m_pSteeringBehaviors;
};