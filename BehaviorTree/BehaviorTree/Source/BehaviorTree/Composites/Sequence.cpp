#include "../Composites/Sequence.h"

void Seqeunce::OnInitialize()
{
	it = m_children.begin();
}

EStatus Seqeunce::OnUpdate()
{
	while (true)
	{
		EStatus status = (*it)->Tick();
		if (status != EStatus::ESuccess)
		{
			return status;
		}

		if (++it == m_children.end())
		{
			return EStatus::ESuccess;
		}
	}
}

void Seqeunce::OnTerminate(EStatus status)
{

}
