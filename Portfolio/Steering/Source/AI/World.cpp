#include "World.h"
#include "Entity.h"

World::World(SDL_Renderer* renderer)
	: m_renderer(renderer)
{
	Entity* entity = new Entity(renderer);
	m_entities.push_back(entity);
	m_entities.push_back(entity);
	m_entities.push_back(entity);
	m_entities.push_back(entity);
	m_entities.push_back(entity);
}

World::~World()
{

}

void World::Update(float deltaTime)
{
	for (auto entity : m_entities)
	{
		entity->Update(deltaTime);
	}
}

void World::Draw()
{
	for (auto entity : m_entities)
	{
		entity->Draw();
	}
}
