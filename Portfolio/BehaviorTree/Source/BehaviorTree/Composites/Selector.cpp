#include "Selector.h"
#include <cassert>

void Selector::OnInitialize()
{
	m_iterator = m_children.begin();
}

EStatus Selector::OnUpdate()
{
	assert(HasChildren());

	while (m_iterator != m_children.end())
	{
		EStatus status = (*m_iterator)->Tick();

		if (m_status != EStatus::EFailure)
		{
			return status;
		}

		m_iterator++;
	}

	return EStatus::EFailure;
}

