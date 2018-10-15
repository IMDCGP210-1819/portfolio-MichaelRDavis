#include "Boid.h"

Boid::Boid()
	: Entity()
{
	m_filename = "Resources\\boid.png";
	m_color = sf::Color::White;

	Initialize();
}

Boid::Boid(std::string file)
	: Entity(file)
{
	m_color = sf::Color::White;

	Initialize();
}

Boid::Boid(std::string file, sf::Color color)
	: Entity(file, color)
{
	Initialize();
}

Boid::~Boid()
{

}

void Boid::Update()
{

}

void Boid::Initialize()
{

}
