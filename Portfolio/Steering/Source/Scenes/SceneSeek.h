#pragma once

#include "IScene.h"
#include <SDL.h>

class Entity;

class SceneSeek : public IScene
{
public:
	SceneSeek();
	~SceneSeek();

	void OnInitialize(SDL_Renderer* renderer);
	void OnUpdate(float deltaTime);
	void OnRender();
	void OnGUIRender();

private:
	SDL_Renderer* m_renderer;

	Entity* m_entity;
	Entity* m_target;
};