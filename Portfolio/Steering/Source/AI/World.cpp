#include "World.h"
#include "Entity.h"
#include <memory>

World::World(SDL_Renderer* renderer)
	: m_renderer(renderer)
{
	m_numEntities = 5;
}

World::~World()
{

}

void World::Initialize()
{
	for (int32_t i = 0; i < m_numEntities; i++)
	{
		std::unique_ptr<Entity> entity = std::make_unique<Entity>(this);
		entity->Initialize();
		m_entities.push_back(entity.get());
	}
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

