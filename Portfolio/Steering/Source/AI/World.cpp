#include "World.h"
#include "Entity.h"
#include <memory>

World::World(SDL_Renderer* renderer)
	: m_renderer(renderer)
{
	m_numEntities = 5;

	std::unique_ptr<Entity> entity = std::make_unique<Entity>(this);
	entity->CreateTexture("Content/boid.png");

	for (int32_t i = 0; i < m_numEntities; i++)
	{
		m_entities.push_back(entity.get());
	}

	LogEntityList();
}

World::~World()
{

}

void World::Initialize()
{
	for (auto entity : m_entities)
	{
		entity->Initialize();
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

