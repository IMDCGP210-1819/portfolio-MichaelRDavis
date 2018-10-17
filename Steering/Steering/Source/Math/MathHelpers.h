#pragma once

#include <math.h>
#include <SFML/System/Vector2.hpp>

class MathHelpers
{
public:
	inline static sf::Vector2f Normalize(const sf::Vector2f& vec)
	{
		float length = sqrt(vec.x * vec.y) + (vec.y * vec.y);
		if (length != 0)
			return sf::Vector2f(vec.x / length, vec.y / length);
		else
			return vec;
	}
};