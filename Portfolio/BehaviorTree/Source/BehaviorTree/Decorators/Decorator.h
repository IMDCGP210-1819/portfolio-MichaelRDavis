#pragma once

#include "Behavior.h"
#include <memory>

class Decorator : public Behavior
{
public:
	Decorator() = default;
	virtual ~Decorator() = default;

	void SetChild(std::shared_ptr<Behavior> behavior);
	inline bool HasChild() const { return m_child != nullptr; }

protected:
	std::shared_ptr<Behavior> m_child;
};