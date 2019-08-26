#pragma once

#include <vector>
#include <SDL.h>

class Entity;

class World
{
public:
	World(SDL_Renderer* renderer);
	~World();

	void Update(float deltaTime);
	void Draw();

private:
	std::vector<Entity*> m_entities;
	SDL_Renderer* m_renderer;
};