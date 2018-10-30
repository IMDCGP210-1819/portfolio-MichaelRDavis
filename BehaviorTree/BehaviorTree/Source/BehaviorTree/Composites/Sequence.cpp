#include "../Composites/Sequence.h"

void Seqeunce::OnInitialize()
{
	m_currentChild = m_children.begin();
}

EStatus Seqeunce::Update()
{
	while (true)
	{
		EStatus status = (*m_currentChild)->Tick();
		if (status != EStatus::ESuccess)
		{
			return status;
		}

		if (++m_currentChild == m_children.end())
		{
			return EStatus::ESuccess;
		}
	}
}
