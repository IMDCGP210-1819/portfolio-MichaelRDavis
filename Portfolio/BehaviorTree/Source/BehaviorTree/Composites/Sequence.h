#pragma once

#include "Composite.h"

class Sequence : public Composite
{
public:
	Sequence() = default;
	~Sequence() = default;

	void OnInitialize() override;
	EStatus OnUpdate() override;
	void OnTerminate(EStatus status) override;
};