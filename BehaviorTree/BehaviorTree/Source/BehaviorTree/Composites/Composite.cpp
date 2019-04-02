#include "Composite.h"

void Composite::AddChild(Task* child)
{
	m_children.push_back(child);
}

void Composite::RemoveChild(Task* child)
{
	std::vector<Task*>::iterator it = std::find(m_children.begin(), m_children.end(), child);
	if (it != m_children.end())
		m_children.erase(it);
}

void Composite::ClearChildren()
{
	m_children.clear();
}
