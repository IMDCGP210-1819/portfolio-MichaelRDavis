#pragma once

#include <memory>
#include "State.h"

template<class T>
class FSM
{
public:
	FSM() = default;
	virtual ~FSM() = default;

	virtual void Update() = 0;

	void GoToState(std::shared_ptr<State<T>> state)
	{
		m_currentState.swap(state);
	}

	void SetOwner(T* newOwner)
	{
		m_owner = newOwner;
	}

	inline std::shared_ptr<T> GetOwner() const
	{
		return m_owner;
	}

protected:
	T* m_owner;
	std::list<std::shared_ptr<State<T>>> m_states;
	std::shared_ptr<State<T>> m_currentState;
	std::shared_ptr<State<T>> m_previousState;
};