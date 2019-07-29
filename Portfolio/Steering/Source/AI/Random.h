#pragma once

#include <random>

class Random
{
public:
	Random() = default;
	~Random() = default;

	static float GetRange(float min, float max)
	{
		std::uniform_real_distribution<float> dist(min, max);
		return dist(m_mt);
	}

private:
	static std::mt19937 m_mt;
};