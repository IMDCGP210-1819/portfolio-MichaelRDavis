#pragma once

#include <cstdint>

namespace AI
{
	class UtilityAction
	{
	public:
		UtilityAction();
		UtilityAction(const UtilityAction&);
		~UtilityAction();

		__forceinline float GetTtime() const { return m_Time; }
		__forceinline int32_t GetPriority() const { return m_Priority; }
		__forceinline bool GetIsInterruptible() const { return m_bIsInterruptible; }

	private:
		float m_Time;
		int32_t m_Priority;
		bool m_bIsInterruptible;
	};
}