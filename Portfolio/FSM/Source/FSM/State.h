#pragma once

#include <list>
#include <memory>

template<class T>
class Transitions;

template<class T>
class State
{
public:
	State() = default;
	virtual ~State() = default;

	virtual void OnEnter(T* owner) = 0;
	virtual void OnUpdate(T* owner) = 0;
	virtual void OnExit(T* owner) = 0;

	std::list<std::shared_ptr<Transitions<T>>> m_transitions;
};