#pragma once

#include "Decorator.h"

class Repeat : public Decorator
{
public:
	Repeat(int32_t limit);
	~Repeat() = default;

	virtual EStatus OnUpdate() override;

protected:
	int32_t m_limit;
	int32_t m_counter;
};