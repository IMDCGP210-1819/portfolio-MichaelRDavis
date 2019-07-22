#include "Repeat.h"

Repeat::Repeat(int32_t limit)
	: m_limit(limit)
	, m_counter(0)
{

}

EStatus Repeat::OnUpdate()
{
	m_child->Tick();

	if (m_limit > 0 && ++m_counter == m_limit)
	{
		return EStatus::ESuccess;
	}

	return EStatus::ERunning;
}

