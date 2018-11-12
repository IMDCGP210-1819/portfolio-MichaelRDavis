#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class Boid;

class World
{
public:
	World();
	~World();

	void Render(sf::RenderWindow& window);
	void Update(sf::Time& time);

	static std::vector<Boid*> m_renderables;
	const int MAX_BOIDS = 5;
	const int WORLD_BOUNDS_X = 1024;
	const int WORLD_BOUNDS_Y = 768;
};