#pragma once

#include "../Composites/Parallel.h"

class Behavior;

class Monitor : public Parallel
{
public:
	void AddCondition(Behavior* condition);
	void AddAction(Behavior* action);
};