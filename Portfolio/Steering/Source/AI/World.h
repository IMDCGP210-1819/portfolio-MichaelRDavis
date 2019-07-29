#pragma once

#include <list>
#include <iostream>
#include <SDL.h>

class Entity;

class World
{
public:
	World(SDL_Renderer* renderer);
	~World();

	void Initialize();
	void Update(float deltaTime);
	void Draw();

#ifdef _DEBUG
	void LogEntityList()
	{
		for (auto entity : m_entities)
		{
			const std::type_info& entityType = typeid(entity);
			std::cout << entityType.name() << std::endl;
		}
	}
#endif

	inline SDL_Renderer* GetRenderer() const
	{
		return m_renderer;
	}

private:
	SDL_Renderer* m_renderer;

	std::list<Entity*> m_entities;
	int32_t m_numEntities;
};