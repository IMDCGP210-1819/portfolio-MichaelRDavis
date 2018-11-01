#include <SFML/Graphics.hpp>
#include "Entities/Boid.h"
#include "Entities/World.h"

const int MAX_BOIDS = 5;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Steering");

	for (int i = 0; i < MAX_BOIDS; i++)
	{
		Boid* boid = new Boid();
	}

	sf::Clock clock;

	World world;

	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		world.Render(window);
		world.Update(elapsed);

		window.display();
	}

	return 0;
}