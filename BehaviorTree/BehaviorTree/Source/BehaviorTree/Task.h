#pragma once

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
class Task
{
public:
	/** Default Task Constructor. */
	Task();

	/** Default Task Destructor. */
	virtual ~Task();

	/** Initialize the task. */
	virtual void OnInitialize() = 0;

	/** Update the task. */
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

	/** Is the task terminated? */
	bool IsTerminated() const;

	/** Is the task running? */
	bool IsRunning() const;

	/** Get the current status of the task. */
	EStatus GetStatus() const;

private:
	/** Current status of the task */
	EStatus m_status;
};