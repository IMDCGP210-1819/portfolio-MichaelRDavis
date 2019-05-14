#include "Task.h"

Task::Task()
	: m_status(EStatus::EInvalid)
{

}

Task::Task(const std::shared_ptr<Blackboard>& blackboard)
	: m_blackbaord(blackboard)
{

}

Task::~Task()
{

}

EStatus Task::Tick()
{
	if (m_status != EStatus::ERunning)
		OnInitialize();
	m_status = OnUpdate();
	if (m_status != EStatus::ERunning)
		OnTerminate(m_status);
	return m_status;
}

void Task::Reset()
{
	m_status = EStatus::EInvalid;
}

void Task::Abort()
{
	OnTerminate(EStatus::EAborted);
	m_status = EStatus::EAborted;
}

bool Task::IsSuccess() const
{
	return m_status == EStatus::ESuccess;
}

bool Task::IsFailure() const
{
	return m_status == EStatus::EFailure;
}

bool Task::IsTerminated() const
{
	return m_status == EStatus::ESuccess || m_status == EStatus::EFailure;
}

bool Task::IsRunning() const
{
	return m_status == EStatus::ERunning;
}

EStatus Task::GetStatus() const
{
	return m_status;
}
