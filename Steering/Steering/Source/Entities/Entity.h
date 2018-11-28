#pragma once

#include <SFML/Graphics.hpp>

class World;

class Entity : public sf::Transformable
{
public:
	/** Default explicit Entity constructor. */
	explicit Entity();

	/** Entity constructor.
	*	@param file
	*/
	explicit Entity(std::string file);

	/** Entity constructor. 
	*	@param file
	*	@param color
	*/
	explicit Entity(std::string file, sf::Color color);

	/** Default Entity destructor. */
	virtual ~Entity();

	/** Entity update method, called once per frame. */
	virtual void Update(float deltaTime) = 0;

	/** Pure virtual Entity initializer. */
	virtual void Initialize() = 0;

	/** Get the current world pointer. */
	inline World* GetWorld() const { return m_worldObject; }

	/** Get the sprite of the Entity. */
	inline const sf::Sprite GetSprite() const { return m_sprite; }

	/** Set the filename of the Entity. 
	*	@param newFilename - Filename to set.
	*/
	inline void SetFileName(std::string newFilename) { m_filename = newFilename; }

	/** Set the color of the Entity.
	*	@param newColor - Color to set.
	*/
	inline void SetColor(sf::Color newColor) { m_color = newColor; }

	/** Returns the velocity of the Entity. */
	inline sf::Vector2f GetVelocity() const { return m_velocity; }

	/** Returns the direction of the Entity. */
	inline sf::Vector2f GetDirection() const { return m_direction; }

	/** Returns the mass of the Entity. */
	inline float GetMass() const { return m_mass; }

	/** Returns the speed of the Entity. */
	inline float GetSpeed() const { return m_speed; }

	/** Returns the force of the Entity. */
	inline float GetForce() const { return m_force; }

	/** Returns the turning rate of the Entity. */
	inline float GetTurnRate() const { return m_turnRate; }

protected:
	/** Pointer to the world object. */
	World* m_worldObject;

	/** Resource filename of the Entity. */
	std::string m_filename;

	/** 2D sprite of the Entity. */
	sf::Sprite m_sprite;

	/** Texture of the Entity. */
	sf::Texture m_texture;

	/** Color of the Entity. */
	sf::Color m_color;

	/** Velocity of the Entity. */
	sf::Vector2f m_velocity;

	/** Heading of the Entity. */
	sf::Vector2f m_direction;

	/** Side of vector of the Entity. */
	sf::Vector2f m_side;

	/** Current position of the Entity. */
	sf::Vector2f m_position;

	/** Mass of the Entity. */
	float m_mass;

	/** Speed of the Entity. */
	float m_speed;

	/** Force of the Entity. */
	float m_force;

	/** Turning speed of the Entity. */
	float m_turnRate;
};

