#include "Composite.h"

Composite::Composite()
	: m_iterator(m_children.begin())
{

}

void Composite::AddChildren(std::shared_ptr<Behavior> behavior)
{
	m_children.push_back(behavior);
}
