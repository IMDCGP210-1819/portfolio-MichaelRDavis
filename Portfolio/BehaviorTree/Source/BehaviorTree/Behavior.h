#pragma once

#include <cstdint>

enum class EStatus : uint8_t
{
	EInvalid,
	ESuccess,
	EFailure,
	ERunning,
	EAborted
};

class Behavior
{
public:
	Behavior();
	virtual ~Behavior() = default;

	virtual EStatus OnUpdate() = 0;
	virtual void OnInitialize() = 0;
	virtual void OnTerminate(EStatus status) = 0;

	EStatus Tick();
	void Reset();
	void Abort();

	inline bool IsSuccess() const { return m_status == EStatus::ESuccess; }
	inline bool IsFailure() const { return m_status == EStatus::EFailure; }
	inline bool IsRunning() const { return m_status == EStatus::ERunning; }
	inline bool IsTerminated() const { return IsSuccess() || IsFailure(); }

	inline EStatus GetStatus() const
	{
		return m_status;
	}

protected:
	EStatus m_status;
};