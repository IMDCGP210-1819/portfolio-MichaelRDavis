#pragma once

#include "Behavior.h"
#include <iostream>

class TestBehavior : public Behavior
{
public:
	void OnInitialize() override
	{

	}

	EStatus OnUpdate() override
	{
		std::cout << "Test Behavior" << std::endl;
		return EStatus::ESuccess;
	}

	void OnTerminate(EStatus status) override
	{

	}
};