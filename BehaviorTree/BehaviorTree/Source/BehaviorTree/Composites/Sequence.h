#pragma once

#include "../Composites/Composite.h"

class Seqeunce : public Composite
{
public:
	virtual void OnInitialize() override;
	virtual EStatus Update() override;

protected:
	std::vector<Task*>::iterator m_currentChild;
};