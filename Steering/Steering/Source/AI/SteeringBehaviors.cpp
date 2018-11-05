#include "SteeringBehaviors.h"
#include "Entities/Entity.h"
#include "Entities/Boid.h"
#include "Math/MathLibrary.h"
#include <algorithm>

SteeringBehaviors::SteeringBehaviors()
{
	m_owner = nullptr;
	m_activeBehavior = EBehavior::ENone;
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

sf::Vector2f SteeringBehaviors::Calculate(Entity* owner)
{
	sf::Vector2f velocity = m_owner->GetVelocity();

	if (m_activeBehavior == EBehavior::ENone)
	{
		return Math::ZeroVector;
	}
	else if (m_activeBehavior == EBehavior::ESeek)
	{
		Boid* boid = reinterpret_cast<Boid*>(owner);
		velocity = Seek(boid->m_seekTarget);
		return velocity;
	}
	else if (m_activeBehavior == EBehavior::EFlee)
	{
		Boid* boid = reinterpret_cast<Boid*>(owner);
		return velocity = Flee(boid->m_fleeTarget, boid->m_fleeDistance);
	}

	else if (m_activeBehavior == EBehavior::EArrive)
	{
		Boid* boid = reinterpret_cast<Boid*>(owner);
		return velocity = Arrive(boid->m_arriveTarget, 0.5f);
	}
	else if (m_activeBehavior == EBehavior::EPursuit)
	{
		Boid* boid = reinterpret_cast<Boid*>(owner);
		return velocity = Pursuit(nullptr);
	}
	else
	{
		return Math::ZeroVector;
	}
}

sf::Vector2f SteeringBehaviors::Seek(sf::Vector2f targetVector)
{
	sf::Vector2f velocity = Math::Normalize(m_owner->getPosition() - targetVector) * m_owner->GetSpeed();
	return velocity - m_owner->GetVelocity();
}

sf::Vector2f SteeringBehaviors::Flee(sf::Vector2f targetVector, float fleeDistance)
{
	const float fleeDistSq = fleeDistance * fleeDistance;
	if (Math::LengthSquared(m_owner->getPosition(), targetVector) > fleeDistSq)
	{
		return Math::ZeroVector;
	}

	sf::Vector2f velocity = Math::Normalize(m_owner->getPosition() - targetVector) * m_owner->GetSpeed();
	return velocity - m_owner->GetVelocity();
}

sf::Vector2f SteeringBehaviors::Arrive(sf::Vector2f targetVector, float deacceleration)
{
	const sf::Vector2f& targetPosition = targetVector - m_owner->getPosition();
	float distance = Math::Length(targetPosition - m_owner->getPosition());
	if (distance > 0.0f)
	{
		const float deaccel = 0.3f;
		float speed = distance / (deacceleration * deaccel);
		speed = std::min<float>(speed, m_owner->GetSpeed());

		sf::Vector2f velocity = targetPosition * m_owner->GetSpeed() / distance;
		return velocity - m_owner->GetVelocity();
	}

	return Math::ZeroVector;
}

sf::Vector2f SteeringBehaviors::Pursuit(const Entity* intersectingEntity)
{
	sf::Vector2f evaderPos = intersectingEntity->getPosition() - m_owner->getPosition();

	float relDirection = Math::DotProduct(m_owner->GetDirection(), intersectingEntity->GetDirection());

	if (Math::DotProduct(evaderPos, m_owner->GetDirection()) > 0 && relDirection < -0.95f)
	{
		return Seek(intersectingEntity->getPosition());
	}

	float heading = Math::Length(evaderPos) / (m_owner->GetSpeed() + intersectingEntity->GetSpeed());

	return Seek(intersectingEntity->getPosition() + intersectingEntity->GetVelocity() * heading);
}

