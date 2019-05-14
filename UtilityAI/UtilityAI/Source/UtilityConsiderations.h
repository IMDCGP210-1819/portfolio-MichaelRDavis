#pragma once

namespace AI
{
	template<typename T>
	class UtilityConsiderations
	{
	public:
		UtilityConsiderations();
		UtilityConsiderations(const UtilityConsiderations&);
		~UtilityConsiderations();

	private:
		std::shared_ptr<UtilityProperty<T>> m_Property;
	};
}