#pragma once

/** Valid states for behaviors. */
enum class EStatus : unsigned char
{
	EInvalid,
	ESuccess,
	EFailure,
	ERunning,
	EAborted
};

/** Base class for all behaviors. */
class Behavior
{
public:
	Behavior();
	virtual ~Behavior();

	/** Initialize behavior */
	virtual void OnInitialize() = 0;

	/** Update behavior */
	virtual EStatus Update() = 0;

	/** Terminate behavior
	*	@param status - The status of our behavior		
	*/
	virtual void OnTerminate(EStatus status) = 0;

	/** Tick the behavior */
	EStatus Tick();

	/** Reset the behavior */
	void Reset();

	/** Abort the behavior */
	void Abort();

	/** Is the behavior terminated? */
	bool IsTerminated() const;

	/** Is the behavior running? */
	bool IsRunning() const;

	/** Get the current status of the behavior */
	EStatus GetStatus() const;

private:
	EStatus m_status;
};