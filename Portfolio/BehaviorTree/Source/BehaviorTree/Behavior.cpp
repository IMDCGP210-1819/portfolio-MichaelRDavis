#include "Behavior.h"

Behavior::Behavior()
	: m_status(EStatus::EInvalid)
{

}

EStatus Behavior::Tick()
{
	if (m_status != EStatus::ERunning)
	{
		OnInitialize();
	}

	m_status = OnUpdate();

	if (m_status != EStatus::ERunning)
	{
		OnTerminate(m_status);
	}

	return m_status;
}

void Behavior::Reset()
{
	m_status = EStatus::EInvalid;
}

void Behavior::Abort()
{
	OnTerminate(EStatus::EAborted);
	m_status = EStatus::EAborted;
}
