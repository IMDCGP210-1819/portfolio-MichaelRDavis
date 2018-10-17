#pragma once

#include <SFMl/System/Vector2.hpp>

class Entity;

class SteeringBehaviors
{
public:
	SteeringBehaviors();
	~SteeringBehaviors();

	void SetOwner(Entity* newOnwer);

	sf::Vector2f Seek(sf::Vector2f targetVector);
	sf::Vector2f Flee(sf::Vector2f targetVector);
	sf::Vector2f Arrive(sf::Vector2f targetVector);

private:
	Entity* m_owner;
};