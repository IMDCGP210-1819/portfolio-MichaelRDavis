#pragma once

#include "../Task.h"

class Decorator : public Task
{
public:
	Decorator(Task* child);

protected:
	Task* m_pChild;
};