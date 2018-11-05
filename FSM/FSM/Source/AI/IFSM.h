#pragma once

template<class T>
class IState;

template<class T>
class IFSM
{
public:
	/** Update the finite state machine, called once per frame. 
	*   @param owner - The owner to update.
	*/
	virtual void Update(T* owner) = 0;

	/** The initial state of the finite state machine. */
	IState<T>* m_pInitialState;

	/** The currently active state of the finite state machine. */
	IState<T>* m_pActiveState;
};