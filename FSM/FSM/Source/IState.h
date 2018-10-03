#pragma once

template<class T>
class ITransition;

template<class T>
class IState
{
public:
	virtual void OnEnter(T* owner) = 0;;
	virtual void OnUpdate(T* owner) = 0;
	virtual void OnExit(T* owner) = 0;
};