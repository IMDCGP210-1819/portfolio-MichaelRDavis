#include "SceneMenu.h"
#include <imgui.h>

SceneMenu::SceneMenu(IScene*& scene)
	: m_currentScene(scene)
{

}

void SceneMenu::OnInitialize(SDL_Renderer* renderer)
{

}

void SceneMenu::OnUpdate(float deltaTime)
{

}

void SceneMenu::OnRender()
{

}

void SceneMenu::OnGUIRender()
{
	for (auto& scene : m_scenes)
	{
		if (ImGui::Button(scene.first.c_str()))
		{
			m_currentScene = scene.second();
		}
	}
}