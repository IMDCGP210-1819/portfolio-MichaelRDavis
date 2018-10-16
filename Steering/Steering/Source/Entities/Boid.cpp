#include "Boid.h"
#include "../AI/SteeringBehaviors.h"

std::vector<Boid*> Boid::m_renderables;

Boid::Boid()
	: Entity()
{
	m_filename = "Resources\\boid.png";
	m_color = sf::Color::White;

	m_pSteeringBehaviors = new SteeringBehaviors();
	if (m_pSteeringBehaviors)
	{

	}

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
	delete m_pSteeringBehaviors;
}

void Boid::Update()
{

}

void Boid::Initialize()
{
	setPosition(30.0f, 30.0f);

	m_texture.loadFromFile(m_filename);
	m_texture.setSmooth(true);

	m_sprite.setTexture(m_texture);
	m_sprite.setColor(m_color);

	m_renderables.push_back(this);
}
