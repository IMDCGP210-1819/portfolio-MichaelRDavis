#pragma once

#include "../Composites/Parallel.h"

class Task;

class Monitor : public Parallel
{
public:
	void AddCondition(Task* condition);
	void AddAction(Task* action);
};