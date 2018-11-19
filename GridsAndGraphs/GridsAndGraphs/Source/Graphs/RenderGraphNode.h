#pragma once

#include "../Graphs/GraphNodeBase.h"
#include <SFML/Graphics.hpp>

class RenderGraphNode : public GraphNodeBase
{
public:
	RenderGraphNode();
	~RenderGraphNode();

	void Draw(sf::RenderWindow& window);

protected:
	sf::Vector2f m_Position;
	sf::Color m_pointColor;
	sf::CircleShape m_Point;
	const float m_pointSize = 5.0f;
};