#include "../Graphs/RenderGraphNode.h"

RenderGraphNode::RenderGraphNode()
{

}

RenderGraphNode::~RenderGraphNode()
{

}

void RenderGraphNode::Draw(sf::RenderWindow& window)
{
	sf::CircleShape m_Point(m_pointSize);
	m_Point.setFillColor(sf::Color::White);
	window.draw(m_Point);
}

void RenderGraphNode::SetPosition(sf::Vector2f newPosition)
{
	m_Position = newPosition;
}

void RenderGraphNode::SetColor(sf::Color newColor)
{
	m_pointColor = newColor;
}
