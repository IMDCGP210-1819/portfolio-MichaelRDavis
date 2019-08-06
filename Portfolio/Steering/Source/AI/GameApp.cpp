#include "GameApp.h"
#include <imgui.h>
#include <imgui_sdl.h>

GameApp::GameApp()
{
	m_pWindow = nullptr;
	m_pRenderer = nullptr;
	m_scene = nullptr;
	m_menu = nullptr;
	m_windowWidth = 0;
	m_windowHeight = 0;
	m_isShutdown = false;
}

GameApp::~GameApp()
{
	Shutdown();
}

void GameApp::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
	}

	SDL_DisplayMode displayMode;

	for (int32_t i = 0; i < SDL_GetNumVideoDisplays(); i++)
	{
		int32_t displayCount = SDL_GetCurrentDisplayMode(i, &displayMode);
		if (displayCount != 0)
		{
			SDL_Log("Could not get display mode for video display %d: %s", i, SDL_GetError());
		}

		m_windowWidth = displayMode.w;
		m_windowHeight = displayMode.h;
	}

	uint32_t windowFlags = SDL_WINDOW_ALLOW_HIGHDPI;
	m_pWindow = SDL_CreateWindow("Steering", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_windowWidth, m_windowHeight, windowFlags);
	if (m_pWindow == nullptr)
	{
		SDL_Log("Could not create window: %s", SDL_GetError());
	}

	SDL_SetWindowBordered(m_pWindow, SDL_TRUE);
	SDL_MaximizeWindow(m_pWindow);

	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);
	if (m_pRenderer == nullptr)
	{
		SDL_Log("Could not create renderer: %s", SDL_GetError());
	}

	ImGui::CreateContext();
	ImGuiSDL::Initialize(m_pRenderer, m_windowWidth, m_windowHeight);
}

void GameApp::Shutdown()
{
	delete m_scene;
	if (m_scene != m_menu)
	{
		delete m_menu;
	}

	ImGuiSDL::Deinitialize();
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	ImGui::DestroyContext();
	SDL_Quit();
}

void GameApp::Update()
{
	float deltaTime = (float)SDL_GetTicks() / 1000;
	HandleEvents();

	Clear();

	ImGui::NewFrame();

	if (m_scene)
	{
		m_scene->OnInitialize(m_pRenderer);
		m_scene->OnUpdate(deltaTime);
		m_scene->OnRender();

		ImGui::Begin("Scenes", &m_isMenuActive, ImGuiWindowFlags_MenuBar);
		if (m_scene != m_menu && ImGui::Button("Back"))
		{
			delete m_scene;
			m_scene = m_menu;
		}

		m_scene->OnGUIRender();
		ImGui::End();
	}

	ImGui::Render();
	ImGuiSDL::Render(ImGui::GetDrawData());

	SwapBuffers();
}

void GameApp::HandleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_isShutdown = true;
			Shutdown();
			break;
		}
	}
}

void GameApp::Clear()
{
	SDL_RenderClear(m_pRenderer);
}

void GameApp::SwapBuffers()
{
	SDL_RenderPresent(m_pRenderer);
}

void GameApp::Draw()
{
	Clear();
	SwapBuffers();
}
