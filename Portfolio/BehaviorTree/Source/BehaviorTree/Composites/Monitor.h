#pragma once

#include "Parallel.h"

class Monitor : public Parallel
{
public:
	Monitor() = default;
	~Monitor() = default;

	void AddCondition(std::shared_ptr<Behavior> condition);
	void AddAction(std::shared_ptr<Behavior> action);
};