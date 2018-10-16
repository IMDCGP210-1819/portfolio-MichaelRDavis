#pragma once

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

	void Update() override;
	void Initialize() override;

	inline const sf::Vector2f GetDirection() const { return m_direction; }

	static std::vector<Boid*> m_renderables;

protected:
	SteeringBehaviors* m_pSteeringBehaviors;

	sf::Vector2f m_direction;
};