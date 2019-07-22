#pragma once

#include <memory>
#include <SDL.h>
#include <vmath.h>
#include <string>

class SteeringBehavior;
class World;

class Entity
{
public:
	Entity(World* world);
	~Entity();

	virtual void Initialize();
	virtual void Update(float deltaTime);
	virtual void Draw();

	void CreateTexture(const std::string& filePath);

protected:
	SDL_Texture* m_texture;
	World* m_world;
	std::unique_ptr<SteeringBehavior> m_behavior;

	Vector2f m_velocity;
	Vector2f m_position;

	int32_t m_texWidth;
	int32_t m_texHeight;
	int32_t m_drawOrder;
	float m_scale;
	float m_rotation;
};