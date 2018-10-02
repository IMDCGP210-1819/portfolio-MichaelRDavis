#pragma once

#include <iostream>

class Critter;

class Game
{
public:
	Game();
	~Game();

	void Startup();
	void Run();

	void EvaluateUserInput(std::string Input);

	std::string GetUserInput(std::string Input);
	inline bool GetIsRunning() const { return bIsRunning; }

private: 
	Critter* CritterPet;
	bool bIsRunning;
};