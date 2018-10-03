#pragma once

template<class T>
class IState;

template<class T>
class IFSM
{
public:
	virtual void Update(T* owner) = 0;
	IState<T>* initialState;
	IState<T>* activeState;
};