#include "MathLibrary.h"

sf::Vector2f Math::ZeroVector = sf::Vector2f::Vector2(0.0f, 0.0f);

template<class T>
const T& Math::Min(const T& a, const T& b)
{
	return !(b < a) ? a : b;
}

template<class T>
const T& Math::Max(const T& a, const T& b)
{
	return (a < b) ? b : a;
}

float Math::Length(const sf::Vector2f& vec)
{
	float length = (float)sqrt(vec.x * vec.x) + (vec.y * vec.y);
	return length;
}

float Math::LengthSquared(const sf::Vector2f& vec, const sf::Vector2f& vec2)
{
	float y = vec2.y - vec.y;
	float x = vec2.x - vec.x;
	return y * y + x * x;
}

float Math::DotProduct(const sf::Vector2f& vec1, const sf::Vector2f& vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y;
}

sf::Vector2f Math::Normalize(const sf::Vector2f& vec)
{
	float length = Length(vec);
	if (length != 0)
		return sf::Vector2f(vec.x / length, vec.y / length);
	else
		return vec;
}
