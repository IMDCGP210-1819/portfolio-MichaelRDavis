#include "../Graphs/GraphNodeBase.h"

GraphNodeBase::GraphNodeBase()
	: m_Index(0)
{

}

GraphNodeBase::GraphNodeBase(int index)
	: m_Index(index)
{

}

GraphNodeBase::~GraphNodeBase()
{

}

void GraphNodeBase::SetIndex(int newIndex)
{
	m_Index = newIndex;
}
