#pragma once

#include <list>
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

	inline SDL_Renderer* GetRenderer() const
	{
		return m_renderer;
	}

private:
	SDL_Renderer* m_renderer;

	std::list<Entity*> m_entities;
	int32_t m_numEntities;
};