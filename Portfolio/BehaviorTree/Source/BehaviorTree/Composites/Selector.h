#pragma once

#include "Composite.h"

class Selector : public Composite
{
public:
	Selector() = default;
	~Selector() = default;

	void OnInitialize() override;
	EStatus OnUpdate() override;
};