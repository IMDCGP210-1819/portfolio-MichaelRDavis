#include "Boid.h"
#include "../AI/SteeringBehaviors.h"
#include "../Math/Random.h"

std::vector<Boid*> Boid::m_renderables;

Boid::Boid()
	: Entity()
{
	m_filename = "Resources\\boid.png";
	m_color = sf::Color::White;

	m_pSteeringBehaviors = new SteeringBehaviors();
	if (m_pSteeringBehaviors)
	{
		m_pSteeringBehaviors->SetOwner(this);
	}

	m_speed = 5.0f;

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

void Boid::Update(float deltaTime)
{
	sf::Vector2f pos = m_pSteeringBehaviors->Calculate(this);
	setPosition(pos);
}

void Boid::Initialize()
{
	setPosition(30.0f, 30.0f);

	m_texture.loadFromFile(m_filename);
	m_texture.setSmooth(true);

	m_sprite.setTexture(m_texture);
	m_sprite.setColor(m_color);

	float angle = FRandom::Instance()->GetRange(0, 361);
	setRotation(angle);

#pragma warning(push)
#pragma warning(disable : 4244)
	m_velocity = sf::Vector2f(cos((float) angle * M_PI / 180.0f), sin((float) angle * M_PI / 180.0f));
#pragma warning(pop)

	m_renderables.push_back(this);
}
