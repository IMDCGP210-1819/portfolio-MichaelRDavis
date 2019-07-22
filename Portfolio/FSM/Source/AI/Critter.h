#pragma once

#include <cstdint>
#include <memory>

class CritterFSM;

class Critter
{
public:
	Critter();
	~Critter();

	void Update();

	void Talk();

	void SetHappiness(int32_t val);

	inline int32_t GetHappiness() const { return m_happiness; }
	inline int32_t GetMaxHappiness() const { return m_maxHappiness; }

private:
	std::unique_ptr<CritterFSM> m_stateMachine;

	int32_t m_happiness;
	int32_t m_maxHappiness;
};