#pragma once

class SteeringBehaviors
{
public:
	SteeringBehaviors();
	~SteeringBehaviors();

	void Seek();
	void Flee();
	void Arrive();
};