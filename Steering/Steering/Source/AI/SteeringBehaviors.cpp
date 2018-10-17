#include "SteeringBehaviors.h"
#include "Entities/Entity.h"

SteeringBehaviors::SteeringBehaviors()
{

}

SteeringBehaviors::~SteeringBehaviors()
{

}

void SteeringBehaviors::SetOwner(Entity* newOnwer)
{
	m_owner = newOnwer;
}

sf::Vector2f SteeringBehaviors::Seek(sf::Vector2f targetVector)
{
	sf::Vector2f velocity;
	return velocity;
}

sf::Vector2f SteeringBehaviors::Flee(sf::Vector2f targetVector)
{
	sf::Vector2f velocity;
	return velocity;
}

sf::Vector2f SteeringBehaviors::Arrive(sf::Vector2f targetVector)
{
	sf::Vector2f velocity;
	return velocity;
}

