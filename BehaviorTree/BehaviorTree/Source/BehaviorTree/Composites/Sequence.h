#pragma once

#include "../Composites/Composite.h"

class Seqeunce : public Composite
{
public:
	void OnInitialize() override;
	EStatus OnUpdate() override;
	void OnTerminate(EStatus status) override;
};