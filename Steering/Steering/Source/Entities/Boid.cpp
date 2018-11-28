#include "Boid.h"
#include "../AI/SteeringBehaviors.h"
#include "../Math/Random.h"
#include "../Math/MathLibrary.h"
#include "../Entities/World.h"

Boid::Boid()
	: Entity()
{
	m_filename = "Resources\\boid.png";
	m_color = sf::Color::White;

	m_pSteeringBehaviors = new SteeringBehaviors();
	if (m_pSteeringBehaviors)
	{
		m_pSteeringBehaviors->SetOwner(this);
		m_pSteeringBehaviors->SetBehavior(EBehavior::ESeek);
	}

	m_speed = 0.5f;
	m_velocity = Math::ZeroVector;
	m_fleeDistance = 100.0f;
	m_deacceleration = 0.5f;
	m_seekTarget = sf::Vector2f(150.0f, 150.0f);
	
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
	sf::Vector2f force = m_pSteeringBehaviors->Calculate(this);
	sf::Vector2f accel = force / m_mass;
	m_velocity += accel * deltaTime;
	Math::Truncate(m_velocity, m_speed);
	m_position += m_velocity * deltaTime;
	if (Math::LengthSquared(m_velocity) > 0.00000001)
	{
		m_direction = Math::Normalize(m_velocity);
		m_side = Math::Perpendicular(m_direction);
	}
	setPosition(m_position);
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

	m_worldObject->m_renderables.push_back(this);
}
