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
	/** Default constructor. */
	SteeringBehaviors();

	/** Default destructor. */
	~SteeringBehaviors();

	/** Set the owner of this behavior 
	*   @param newOwner - Owner to set
	*/
	void SetOwner(Entity* newOnwer);

	/** Set the active behavior
	*   @param newBehavior - Behavior to set
	*/
	void SetBehavior(EBehavior newBehavior);

	/** Calculate the vector of our behavior 
	*   @param - Owner of this behavior
	*/
	sf::Vector2f Calculate(Entity* owner);

	/** Moves the owning entity towards a target position 
	*	@param targetVector - The vector target to move to
	*/
	sf::Vector2f Seek(sf::Vector2f targetVector);

	/** Moves the owning entity away from a target position 
	*   @param targetVector - The vector to move away from
	*   @param fleeDistance - 
	*/
	sf::Vector2f Flee(sf::Vector2f targetVector, float fleeDistance);

	/** Moves the owning entity towards a target vector, but attempts to arrive at the target vector at zero velocity 
	*   @param targetVector - The target vector to arrive at
	*	@param deacceleration - 
	*/
	sf::Vector2f Arrive(sf::Vector2f targetVector, float deacceleration);

private:
	/** The owner of this behavior */
	Entity* m_owner;

	/** The currently active behavior */
	EBehavior m_activeBehavior;
};