#pragma once

template<typename T>
class Blackboard
{
public:
	Blackboard();
	virtual ~Blackboard();

protected:
	T type;
};
