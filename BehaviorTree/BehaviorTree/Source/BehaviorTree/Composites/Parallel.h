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
	EPolicy m_successPolicy;

};