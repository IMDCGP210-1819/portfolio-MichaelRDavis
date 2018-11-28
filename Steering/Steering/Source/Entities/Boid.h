#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include "Entity.h"

class SteeringBehaviors;

class Boid : public Entity
{
public:
	/** Explicit default constructor. */
	explicit Boid();

	/** Explicit constructor. 
	*	@param file - Set the texture of the entity via a resource filename.
	*/
	explicit Boid(std::string file);

	/** Explicit constructor. 
	*   @param file - Set the texture of the entity via a resource filename.
	*   @param color - Set the color of the entity.
	*/
	explicit Boid(std::string file, sf::Color color);

	/** Default destructor. */
	~Boid();

	/** Update this entity, once per frame. */
	void Update(float deltaTime) override;

	/** Initialize this entity, called after constructor. */
	void Initialize() override;

	/** The steering behavior of this entity. */
	inline SteeringBehaviors* GetSteeringBehavior() const { return m_pSteeringBehaviors; }

public:
	/** Behavior properties. */
	float m_fleeDistance;
	float m_deacceleration;
	sf::Vector2f m_seekTarget;
	sf::Vector2f m_fleeTarget;
	sf::Vector2f m_arriveTarget;

	/** Pointer to the world object */
	World* m_world;

protected:
	/** The steering behavior of the entity. */
	SteeringBehaviors* m_pSteeringBehaviors;
};