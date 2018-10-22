#pragma once

enum class EStatus : unsigned char
{
	EInvalid,
	ERunning,
};

class Behavior
{
public:
	Behavior()
		: m_status(EStatus::EInvalid)
	{

	}

	virtual ~Behavior()
	{

	}

	EStatus Tick()
	{
		if (m_status != EStatus::ERunning)
			OnInitialize();
		m_status = Update();
		if (m_status != EStatus::ERunning)
			OnTerminate(m_status);
		return m_status;
	}

	virtual void OnInitialize() = 0;
	virtual EStatus Update() = 0;
	virtual void OnTerminate(EStatus status) = 0;

private:
	EStatus m_status;
};