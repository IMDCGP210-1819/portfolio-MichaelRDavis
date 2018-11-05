#include "../Entities/World.h"
#include "../Entities/Boid.h"

std::vector<Boid*> World::m_renderables;

World::World()
{
	for (int i = 0; i < MAX_BOIDS; i++)
	{
		Boid* boid = new Boid();
	}
}

World::~World()
{

}

void World::Render(sf::RenderWindow& window)
{
	for (auto entity : m_renderables)
	{
		window.draw(entity->GetSprite(), entity->getTransform());
	}
}

void World::Update(sf::Time& time)
{
	for (auto entity : m_renderables)
	{
		entity->Update(time.asSeconds());
	}
}
