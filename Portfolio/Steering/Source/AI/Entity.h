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
	Entity(SDL_Renderer* renderer);
	~Entity();

	virtual void Initialize();
	virtual void Update(float deltaTime);
	virtual void Draw();

	void CreateTexture(const std::string& filePath);

	inline Vector2f GetVelcoity() const { return m_velocity; }
	inline Vector2f GetPosition() const { return m_position; }

protected:
	SDL_Texture* m_texture;
	SDL_Renderer* m_renderer;
	std::unique_ptr<SteeringBehavior> m_behavior;

	Vector2f m_velocity;
	Vector2f m_position;

	int32_t m_texWidth;
	int32_t m_texHeight;
	int32_t m_drawOrder;
	float m_scale;
	float m_rotation;
};