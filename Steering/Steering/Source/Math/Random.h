#pragma once

#include <random>

class FRandom
{
public:
	FRandom();
	~FRandom();

	static FRandom* Instance();

	float GetRange(float min, float max);

private:
	static FRandom* m_instance;
	std::mt19937 m_MT;
};

