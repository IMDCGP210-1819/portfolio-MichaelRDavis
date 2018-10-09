#include <iostream>
#include <string>

#include "Critter/CritterGame/Critter.h"

int main()
{
	Critter* critter = new Critter();

	std::cout << "Welcome to the Critter Game!" << std::endl;
	std::cout << "What do you want to do?" << std::endl;
	std::cout << "1. Ignore your critter." << std::endl;
	std::cout << "2. Play with you critter." << std::endl;
	std::cout << "3. Quit game." << std::endl;

	bool isRunning = true;
	while (isRunning)
	{
		critter->RunStateMachine();
		std::cout << "Critter Happiness: " << critter->GetHappy() << std::endl;

		std::string userInput;
		std::cin >> userInput;

		if (userInput == "1")
		{
			std::cout << "You ignored your critter" << std::endl;
			critter->RemoveHappy();
		}
		else if (userInput == "2")
		{
			std::cout << "You played with your critter" << std::endl;
			critter->AddHappy();
		}
		else if (userInput == "3")
		{
			isRunning = false;
		}
	}

	std::cin.get();
	return 0;
}