#pragma once

#include <string>
#include <unordered_map>

/**
 * 
 */
class Blackboard
{
public:
	/**  */
	template<typename T>
	void SetBlackboardkey(std::string key, T type)
	{
		m_keys[key] = type;
	}

	/**  */
	template<typename T>
	T GetBlackboardKey(std::string keyName)
	{
		if (m_keys.find(keyName) == m_keys.end())
		{
			return m_keys<T>[keyName] == nullptr;
		}

		return m_keys[keyName];
	}

	/**  */
	template<typename T>
	bool HasKeyType(std::string keyName)
	{
		return m_keys.find(keyName) != m_keys.end();
	}

protected:
	/** Map of blackboard keys stored in the blackboard. */
	template<typename T>
	static std::unordered_map<std::string, T> m_keys;
};
