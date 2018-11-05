#pragma once

template<class T>
class IState;

template<class T>
class ITransition
{
public:
	/** Checks to see if state transition is valid. 
	*	@param - The owner of the FSM.
	*/
	virtual bool IsValid(T* owner) = 0;

	/** Returns the next state to transition to. 
	*	@param - The owner of the FSM.
	*/
	virtual IState<T>* GetNextState(T* owner) = 0;

	/** Called on transition to the next state.
	*	@param - The owner of the FSM.
	*/
	virtual void OnTransition(T* owner) = 0;
};