#include "Entity.h"

std::vector<Entity*> Entity::m_renderables;

Entity::Entity()
{
	
}

Entity::Entity(std::string file)
	: m_filename(file)
{
	
}

Entity::Entity(std::string file, sf::Color color)
	: m_filename(file)
	, m_color(color)
{
	
}

Entity::~Entity()
{

}

