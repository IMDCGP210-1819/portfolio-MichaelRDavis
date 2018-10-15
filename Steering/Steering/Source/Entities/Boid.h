#pragma once

#include "Entity.h"

class Boid : public Entity
{
public:
	explicit Boid();
	explicit Boid(std::string file);
	explicit Boid(std::string file, sf::Color color);
	~Boid();

	void Update() override;
	void Initialize() override;
};