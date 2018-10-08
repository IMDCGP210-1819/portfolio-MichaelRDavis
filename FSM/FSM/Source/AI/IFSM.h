#pragma once

template<class T>
class IState;

template<class T>
class IFSM
{
public:
	virtual void Update(T* owner) = 0;
	IState<T>* m_pInitialState;
	IState<T>* m_pActiveState;
};