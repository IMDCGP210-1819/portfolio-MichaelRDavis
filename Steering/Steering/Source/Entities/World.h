#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class Boid;

class World
{
public:
	/** Default World constructor. */
	World();

	/** Default World destructor. */
	~World();

	/** Render all of the Entities in the World. 
	*	@param window - The current render window.
	*/
	void Render(sf::RenderWindow& window);

	/** Update all of the Entities in the world, called once per frame. 
	*	@param time - The current time.
	*/
	void Update(sf::Time& time);

	void Wrap(sf::Vector2f position, int x, int y);

	/** List of all Entities in the world. */
	static std::vector<Boid*> m_renderables;

	/** Max number of Entities allowed in the World */
	const int MAX_BOIDS = 5;

	/** Bounds of the World. */
	const int WORLD_BOUNDS_X = 1024;
	const int WORLD_BOUNDS_Y = 768;
};