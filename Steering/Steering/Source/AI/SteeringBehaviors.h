#pragma once

#include <SFMl/System/Vector2.hpp>

class Entity;

enum class EBehavior : unsigned char
{
	ENone,
	ESeek,
	EFlee,
	EArrive
};

class SteeringBehaviors
{
public:
	SteeringBehaviors();
	~SteeringBehaviors();

	void SetOwner(Entity* newOnwer);
	void SetBehavior(EBehavior newBehavior);
	sf::Vector2f Calculate(Entity* owner);

	sf::Vector2f Seek(sf::Vector2f targetVector);
	sf::Vector2f Flee(sf::Vector2f targetVector);
	sf::Vector2f Arrive(sf::Vector2f targetVector, float deacceleration);

private:
	Entity* m_owner;
	EBehavior m_activeBehavior;
};