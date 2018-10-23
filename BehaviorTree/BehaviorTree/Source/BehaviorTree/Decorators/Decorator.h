#pragma once

#include "../Behavior.h"

class Decorator : public Behavior
{
public:
	Decorator(Behavior* child);

protected:
	Behavior* m_pChild;
};