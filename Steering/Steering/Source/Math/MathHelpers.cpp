#include "MathHelpers.h"

sf::Vector2f MathHelpers::ZeroVector = sf::Vector2f::Vector2(0.0f, 0.0f);

template<class T>
const T& MathHelpers::Min(const T& a, const T& b)
{
	return !(b < a) ? a : b;
}

float MathHelpers::Length(const sf::Vector2f& vec)
{
	float length = (float)sqrt(vec.x * vec.x) + (vec.y * vec.y);
	return length;
}

sf::Vector2f MathHelpers::Normalize(const sf::Vector2f& vec)
{
	float length = Length(vec);
	if (length != 0)
		return sf::Vector2f(vec.x / length, vec.y / length);
	else
		return vec;
}
