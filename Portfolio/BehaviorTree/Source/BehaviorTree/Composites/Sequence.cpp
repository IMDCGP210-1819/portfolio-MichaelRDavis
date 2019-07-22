#include "Sequence.h"
#include <cassert>

void Sequence::OnInitialize()
{
	m_iterator = m_children.begin();
}

EStatus Sequence::OnUpdate()
{
	assert(HasChildren());

	while (true)
	{
		EStatus status = (*m_iterator)->Tick();
		if (status != EStatus::ESuccess)
		{
			return status;
		}

		if (++m_iterator == m_children.end())
		{
			return EStatus::ESuccess;
		}
	}
}

void Sequence::OnTerminate(EStatus status)
{

}
