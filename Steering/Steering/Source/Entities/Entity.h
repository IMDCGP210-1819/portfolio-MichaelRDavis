#pragma once

#include <SFML/Graphics.hpp>

class Entity : public sf::Transformable
{
public:
	explicit Entity();
	explicit Entity(std::string file);
	explicit Entity(std::string file, sf::Color color);
	virtual ~Entity();

	virtual void Update(float deltaTime) = 0;
	virtual void Initialize() = 0;

	inline const sf::Sprite GetSprite() const { return m_sprite; }
	inline void SetFileName(std::string newFilename) { m_filename = newFilename; }
	inline void SetColor(sf::Color newColor) { m_color = newColor; }

protected:
	std::string m_filename;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Color m_color;

	sf::Vector2f m_velocity;
	sf::Vector2f m_direction;

	float m_mass;
	float m_speed;
	float m_force;
	float m_turnRate;
};

