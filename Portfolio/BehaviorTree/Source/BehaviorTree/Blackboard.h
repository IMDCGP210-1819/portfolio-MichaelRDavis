#pragma once

#include <string>
#include <unordered_map>
#include <typeinfo>

class Blackboard
{
public:
	Blackboard() = default;
	~Blackboard() = default;

	template<typename T>
	void SetBlackboardType(const std::string& keyName, T type)
	{
		m_keys[keyName] = type;
	}

	template<typename T>
	T GetBlackboardKey(const std::string& keyName)
	{
		if (m_keys.find(keyName) == m_keys.end())
		{
			return m_keys<T>[keyName] == nullptr;
		}

		return m_keys[keyName];
	}

	template<typename T>
	std::string& GetTypeName(const std::string& keyName)
	{
		if (m_keys.find(keyName) == m_keys.end())
		{
			return m_keys<T>[keyName] == nullptr;
		}

		return typeid(m_keys[keyName]).name();
	}

	template<typename T>
	bool HasKey(const std::string& keyName)
	{
		return m_keys.find(keyName) != m_keys.end();
	}

private:
	template<typename T>
	static std::unordered_map<std::string, T> m_keys;
};