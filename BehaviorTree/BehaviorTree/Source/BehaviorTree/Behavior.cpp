#include "./Behavior.h"

Behavior::Behavior()
	: m_status(EStatus::EInvalid)
{

}

Behavior::~Behavior()
{

}

EStatus Behavior::Tick()
{
	if (m_status != EStatus::ERunning)
		OnInitialize();
	m_status = Update();
	if (m_status != EStatus::ERunning)
		OnTerminate(m_status);
	return m_status;
}

void Behavior::Reset()
{
	m_status = EStatus::EInvalid;
}

void Behavior::Abort()
{

}

bool Behavior::IsTerminated() const
{
	return m_status == EStatus::ESuccess || m_status == EStatus::EFailure;
}

bool Behavior::IsRunning() const
{
	return m_status == EStatus::ERunning;
}

EStatus Behavior::GetStatus() const
{
	return m_status;
}
