#pragma once

#include <random>

class Random
{
public:
	Random() = default;
	~Random() = default;

	template<typename T>
	static T GetRange(T min, T max)
	{
		std::uniform_real_distribution<T> dist(min, max);
		return dist(m_mt);
	}

private:
	static std::mt19937 m_mt;
};