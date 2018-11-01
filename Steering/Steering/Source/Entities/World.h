#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class Boid;

class World
{
public:
	World();

	void Render(sf::RenderWindow& window);
	void Update(sf::Time& time);

	static std::vector<Boid*> m_renderables;
};