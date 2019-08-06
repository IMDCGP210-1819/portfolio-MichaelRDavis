#pragma once

#include <SDL.h>

class IScene
{
public:
	IScene() = default;
	virtual ~IScene() = default;

	virtual void OnInitialize(SDL_Renderer* renderer) = 0;
	virtual void OnUpdate(float deltaTime) = 0;
	virtual void OnRender() = 0;
	virtual void OnGUIRender() = 0;
};