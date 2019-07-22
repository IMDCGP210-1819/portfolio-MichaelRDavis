#include "Decorator.h"

void Decorator::SetChild(std::shared_ptr<Behavior> behavior)
{
	m_child = behavior;
}
