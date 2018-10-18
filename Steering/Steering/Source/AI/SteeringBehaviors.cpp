#include "SteeringBehaviors.h"
#include "Entities/Entity.h"
#include "Math/MathHelpers.h"
#include <algorithm>

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

void SteeringBehaviors::SetBehavior(EBehavior newBehavior)
{
	m_activeBehavior = newBehavior;
}

sf::Vector2f SteeringBehaviors::Seek(sf::Vector2f targetVector)
{
	sf::Vector2f velocity = MathHelpers::Normalize(m_owner->getPosition() - targetVector) * m_owner->GetSpeed();
	return velocity - m_owner->GetVelocity();
}

sf::Vector2f SteeringBehaviors::Flee(sf::Vector2f targetVector)
{
	sf::Vector2f velocity = MathHelpers::Normalize(m_owner->getPosition() - targetVector) * m_owner->GetSpeed();
	return velocity - m_owner->GetVelocity();
}

sf::Vector2f SteeringBehaviors::Arrive(sf::Vector2f targetVector, float deacceleration)
{
	const sf::Vector2f& targetPosition = targetVector - m_owner->getPosition();
	float distance = MathHelpers::Length(targetPosition - m_owner->getPosition());
	if (distance > 0.0f)
	{
		const float deaccel = 0.3f;
		float speed = distance / (deacceleration * deaccel);
		speed = std::min<float>(speed, m_owner->GetSpeed());

		sf::Vector2f velocity = targetPosition * m_owner->GetSpeed() / distance;
		return velocity - m_owner->GetVelocity();
	}

	return MathHelpers::ZeroVector;
}

