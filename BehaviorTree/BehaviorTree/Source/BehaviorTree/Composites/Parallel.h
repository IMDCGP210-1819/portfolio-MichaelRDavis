#pragma once

#include "../Composites/Composite.h"

class Parallel : public Composite
{
public:
	enum class EPolicy : unsigned char
	{
		ERqeuireOne,
		ERequireAll
	};

	Parallel(EPolicy success, EPolicy failure);

protected:
	virtual EStatus Update() override;
	virtual void OnTerminate(EStatus status) override;

protected:
	EPolicy m_successPolicy;
	EPolicy m_failurePolicy;
};