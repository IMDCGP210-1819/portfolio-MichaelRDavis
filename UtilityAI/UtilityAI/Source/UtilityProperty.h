#pragma once

namespace AI
{
	template<typename T>
	class UtilityProperty
	{
	public:
		UtilityProperty()
		{

		}

		UtilityProperty(const UtilityProperty&)
		{

		}

		~UtilityProperty()
		{

		}

		T Value()
		{
			m_CurrentValue = m_Value;
			if (m_CurrentValue < m_MinValue)
			{
				m_CurrentValue = m_MinValue;
			}
			else if (m_CurrentValue > m_MaxValue)
			{
				m_CurrentValue = m_MaxValue;
			}

			m_NormalizedValue = (m_CurrentValue - m_MinValue) / (m_MaxValue - m_MinValue);

			return m_CurrentValue;
		}

	private:
		T m_Value;
		T m_NormalizedValue;
		T m_StartValue;
		T m_CurrentValue;
		T m_MinValue;
		T m_MaxValue;
	};
}