#pragma once

template<class T>
class ITransition;

template<class T>
class IState
{
public:
	/** Called on entry to this state.
	*   @param - The owner of the FSM
	*/
	virtual void OnEnter(T* owner) = 0;

	/** Called in state update, once per frame. 
	*	@param - The owner of the FSM
	*/
	virtual void OnUpdate(T* owner) = 0;

	/** Called on exit to this state.
	*	@param - The owner of the FSm
	*/
	virtual void OnExit(T* owner) = 0;
};