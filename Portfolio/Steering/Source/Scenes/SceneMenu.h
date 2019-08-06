#pragma once

#include "IScene.h"
#include <string>
#include <vector>
#include <functional>
#include <SDL.h>

class SceneMenu : public IScene
{
public:
	SceneMenu(IScene*& scene);
	~SceneMenu() = default;

	void OnInitialize(SDL_Renderer* renderer) override;
	void OnUpdate(float deltaTime) override;
	void OnRender() override;
	void OnGUIRender() override;

	template<typename T>
	inline void AddScene(const std::string& sceneName)
	{
		m_scenes.push_back(std::make_pair(sceneName, []() {return new T(); }));
	}

private:
	IScene*& m_currentScene;
	std::vector<std::pair<std::string, std::function<IScene*()>>> m_scenes;
};