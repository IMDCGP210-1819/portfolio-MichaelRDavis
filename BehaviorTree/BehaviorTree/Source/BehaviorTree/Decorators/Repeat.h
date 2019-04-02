#pragma once

#include "Decorator.h"

class Repeat : public Decorator
{
public:
	virtual EStatus OnUpdate() override;
};