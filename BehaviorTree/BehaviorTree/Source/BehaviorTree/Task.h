#pragma once

#include "Node.h"
#include <memory>

class Blackboard;

/** Valid states for tasks. */
enum class EStatus : uint8_t
{
	EInvalid,
	ESuccess,
	EFailure,
	ERunning,
	EAborted
};

/** Base class for all behavior tasks. */
class Task : public Node
{
public:
	/** Default Task Constructor. */
	Task();

	/** Constructor to initialize a blackboard. */
	Task(const std::shared_ptr<Blackboard>& blackboard);

	/** Default Task Destructor. */
	virtual ~Task();

	/** Initialize the task. */
	virtual void OnInitialize() = 0;

	/** Update the task, called every frame */
	virtual EStatus OnUpdate() = 0;

	/** Terminate the task.
	*	@param status - The status of the task.		
	*/
	virtual void OnTerminate(EStatus status) = 0;

	/** Tick the behavior, called once per frame. */
	EStatus Tick();

	/** Reset the the task. */
	void Reset();

	/** Abort the the task. */
	void Abort();

	/** Is the task successful. */
	bool IsSuccess() const;

	/** Return true if the task failed to run successfully. */
	bool IsFailure() const;

	/** Is the task terminated? */
	bool IsTerminated() const;

	/** Is the task running? */
	bool IsRunning() const;

	/** Get the current status of the task. */
	EStatus GetStatus() const;

protected:
	/** Current status of the task */
	EStatus m_status;

	/** Blackboard pointer. */
	std::shared_ptr<Blackboard> m_blackbaord;
};