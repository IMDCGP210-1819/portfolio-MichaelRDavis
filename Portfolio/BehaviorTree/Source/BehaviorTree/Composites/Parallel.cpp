#include "Parallel.h"

Parallel::Parallel(EPolicy success, EPolicy failure)
	: m_successPolicy(success)
	, m_failurePolicy(success)
{

}

EStatus Parallel::OnUpdate()
{
	size_t successCount = 0;
	size_t failureCount = 0;

	for (auto it : m_children)
	{
		Behavior& behavior = *it;
		if (!behavior.IsTerminated())
		{
			behavior.Tick();
		}

		if (behavior.GetStatus() == EStatus::ESuccess)
		{
			++successCount;

			if (m_successPolicy == EPolicy::ERequireOne)
			{
				return EStatus::ESuccess;
			}
		}

		if (behavior.GetStatus() == EStatus::EFailure)
		{
			++failureCount;

			if (m_failurePolicy == EPolicy::ERequireOne)
			{
				return EStatus::EFailure;
			}
		}

		if (m_failurePolicy == EPolicy::ERequireAll && failureCount == sizeof(size_t))
		{
			return EStatus::EFailure;
		}

		if (m_successPolicy == EPolicy::ERequireAll && successCount == sizeof(size_t))
		{
			return EStatus::ESuccess;
		}

	}

	return EStatus::ERunning;
}

void Parallel::OnTerminate(EStatus status)
{
	for (auto it : m_children)
	{
		Behavior& behavior = *it;
		if (behavior.IsRunning())
		{
			behavior.Abort();
		}
	}
}
