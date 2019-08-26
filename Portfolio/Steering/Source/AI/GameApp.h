#pragma once

#include <SDL.h>
#undef main
#include <memory>
#include <string>

class World;

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
	std::unique_ptr<World> m_world;
	int32_t m_windowWidth;
	int32_t m_windowHeight;
	bool m_isShutdown;
};