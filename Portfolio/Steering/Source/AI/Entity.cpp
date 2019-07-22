#include "Entity.h"
#include "SteeringBehavior.h"
#include "World.h"
#include <SDL_image.h>

Entity::Entity(World* world)
	: m_world(world)
{
	m_texture = nullptr;
	m_velocity = Vector2f(0.0f, 0.0f);
	m_texWidth = 0;
	m_texHeight = 0;
	m_drawOrder = 0;
	m_scale = 1.0f;
	m_rotation = 0.0f;
}

Entity::~Entity()
{
	m_texture = nullptr;
	m_world = nullptr;
}

void Entity::Initialize()
{
	SDL_Log("Init Entity");
	//CreateTexture("Content/boid.png");
}

void Entity::Update(float deltaTime)
{
	SDL_Log("Update Entity");
}

void Entity::Draw()
{
	if (m_texture)
	{
		SDL_Rect rect;
		rect.w = static_cast<int32_t>(m_texWidth * m_scale);
		rect.h = static_cast<int32_t>(m_texHeight * m_scale);
		rect.x = static_cast<int32_t>(m_position.x - rect.w / 2);
		rect.y = static_cast<int32_t>(m_position.y - rect.h / 2);

		SDL_QueryTexture(m_texture, nullptr, nullptr, &rect.w, &rect.h);

		SDL_RenderCopyEx(
			m_world->GetRenderer(),
			m_texture,
			nullptr,
			&rect,
			m_rotation,
			nullptr,
			SDL_FLIP_NONE);

		SDL_Log("Draw Entity");
	}
}

void Entity::CreateTexture(const std::string& filePath)
{
	SDL_Surface* surface = IMG_Load(filePath.c_str());
	if (surface == nullptr)
	{
		std::cout << "Unable to load a texture file " << filePath.c_str() << std::endl;
	}

	m_texture = SDL_CreateTextureFromSurface(m_world->GetRenderer(), surface);
	SDL_FreeSurface(surface);
	if (m_texture == nullptr)
	{
		std::cout << "Failed to create texture for " << filePath.c_str() << std::endl;
	}
}
