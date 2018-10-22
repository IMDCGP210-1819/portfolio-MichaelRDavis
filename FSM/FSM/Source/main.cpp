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
	std::cout << "3. Feed your critter." << std::endl;
	std::cout << "4. Quit game." << std::endl;

	bool isRunning = true;
	while (isRunning)
	{
		critter->RunStateMachine();
		std::cout << "Critter Happiness: " << critter->GetHappiness() << std::endl;
		std::cout << "Critter Hunger: " << critter->GetHunger() << std::endl;

		std::string userInput;
		std::cin >> userInput;

		if (userInput == "1")
		{
			std::cout << "You ignored your critter" << std::endl;
			critter->RemoveHappiness();
			critter->AddHunger();
		}
		else if (userInput == "2")
		{
			std::cout << "You played with your critter" << std::endl;
			critter->AddHappiness();
		}
		else if (userInput == "3")
		{
			std::cout << "You fed your critter" << std::endl;
			critter->RemoveHunger();
		}
		else if (userInput == "4")
		{
			isRunning = false;
		}
	}

	std::cin.get();
	return 0;
}