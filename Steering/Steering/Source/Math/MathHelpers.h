#pragma once

#include <math.h>
#include <SFML/System/Vector2.hpp>

class MathHelpers
{
public:
	// Math functions
	template<class T>
	static const T& Min(const T& a, const T& b);

	// Vector math 
	static float Length(const sf::Vector2f& vec);
	static sf::Vector2f Normalize(const sf::Vector2f& vec);
	static sf::Vector2f ZeroVector;
};
