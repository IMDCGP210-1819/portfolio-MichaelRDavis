#pragma once

#include "IScene.h"

class SceneFlee : public IScene
{
public:
	SceneFlee();
	~SceneFlee();

	void OnInitialize(SDL_Renderer* renderer);
	void OnUpdate(float deltaTime);
	void OnRender();
	void OnGUIRender();
};