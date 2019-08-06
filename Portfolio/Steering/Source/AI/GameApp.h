#pragma once

#include <SDL.h>
#undef main
#include <memory>
#include <string>
#include "Scenes/IScene.h"
#include "Scenes/SceneMenu.h"

class GameApp
{
public:
	GameApp();
	~GameApp();

	void Init();
	void Shutdown();

	void Update();

	void HandleEvents();

	void Clear();
	void SwapBuffers();
	void Draw();

	template<typename T>
	inline void AddMenuScene(const std::string& sceneName)
	{
		m_menu->AddScene<T>(sceneName);
	}

	inline SDL_Window* GetWindow() const
	{
		return m_pWindow;
	}

	inline SDL_Renderer* GetRenderer() const
	{
		return m_pRenderer;
	}

	inline bool GetIsShutdown() const
	{
		return m_isShutdown;
	}

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	IScene* m_scene;
	SceneMenu* m_menu;
	int32_t m_windowWidth;
	int32_t m_windowHeight;
	bool m_isShutdown;
	bool m_isMenuActive;
};