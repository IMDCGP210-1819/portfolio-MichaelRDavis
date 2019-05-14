#include "Composite.h"

Composite::Composite()
{

}

Composite::~Composite()
{

}

void Composite::AddChild(std::shared_ptr<Task> child)
{
	m_children.push_back(child);
}

void Composite::RemoveChild(std::shared_ptr<Task> child)
{
	it = std::find(m_children.begin(), m_children.end(), child);
	if (it != m_children.end())
		m_children.erase(it);
}

void Composite::ClearChildren()
{
	m_children.clear();
}
