#pragma once

#include <math.h>
#include <SFML/System/Vector2.hpp>

class Math
{
public:
	// Math functions
	template<class T>
	static const T& Min(const T& a, const T& b);

	template<class T>
	static const T& Max(const T& a, const T& b);

	// Vector math 
	static float Length(const sf::Vector2f& vec);
	static float LengthSquared(const sf::Vector2f& vec1, const sf::Vector2f& vec2);
	static float DotProduct(const sf::Vector2f& vec1, const sf::Vector2f& vec2);
	static sf::Vector2f Normalize(const sf::Vector2f& vec);
	static sf::Vector2f ZeroVector;
};
