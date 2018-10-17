#include "Math/Random.h"

FRandom* FRandom::m_instance = 0;

FRandom::FRandom()
	: m_MT(std::random_device()())
{

}

FRandom::~FRandom()
{

}

FRandom* FRandom::Instance()
{
	if (!m_instance)
		m_instance = new FRandom();
	return m_instance;
}

float FRandom::GetRange(float min, float max)
{
	std::uniform_real_distribution<float> dist(min, max);
	return dist(m_MT);
}