#pragma once

#include "Composite.h"

class Parallel : public Composite
{
public:
	enum class EPolicy : uint8_t
	{
		ERequireOne,
		ERequireAll
	};

	Parallel(EPolicy success, EPolicy failure);
	~Parallel() = default;

protected:
	virtual EStatus OnUpdate() override;
	virtual void OnTerminate(EStatus status) override;

	EPolicy m_successPolicy;
	EPolicy m_failurePolicy;
};