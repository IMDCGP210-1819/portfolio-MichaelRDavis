#include "SceneSeek.h"
#include "AI/Entity.h"

SceneSeek::SceneSeek()
{

}

SceneSeek::~SceneSeek()
{

}

void SceneSeek::OnInitialize(SDL_Renderer* renderer)
{
	m_renderer = renderer;
	m_entity = new Entity(renderer);
	m_entity->CreateTexture("Content/boid.png");
	m_entity->Initialize();

	m_target = new Entity(renderer);
	m_target->CreateTexture("Content/boid.png");
	m_target->Initialize();
}

void SceneSeek::OnUpdate(float deltaTime)
{
	m_entity->Update(deltaTime);
	m_target->Update(deltaTime);
}

void SceneSeek::OnRender()
{
	m_entity->Draw();
	m_target->Draw();
}

void SceneSeek::OnGUIRender()
{

}
