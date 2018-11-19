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
