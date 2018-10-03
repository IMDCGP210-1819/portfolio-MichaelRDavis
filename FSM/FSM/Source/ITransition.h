#pragma once

template<class T>
class IState;

template<class T>
class ITransition
{
public:
	virtual bool IsValid(T* owner) = 0;
	virtual IState<T>* GetNextState(T* owner) = 0;
	virtual void OnTransition(T* owner) = 0;
};