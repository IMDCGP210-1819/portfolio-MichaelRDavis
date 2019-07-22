#include <iostream>
#include "AI/Critter.h"

int main()
{
	std::cout << "Welcome to the Critter Game!" << std::endl;
	std::cout << "What do you want to do?" << std::endl;
	std::cout << "1. Ignore your critter." << std::endl;
	std::cout << "2. Play with you critter." << std::endl;
	std::cout << "3. Quit game." << std::endl;

	std::unique_ptr<Critter> critter = std::make_unique<Critter>();

	bool isRunning = true;
	while (isRunning)
	{
		// Update the critter finite state machine
		critter->Update();


	}

	return 0;
}