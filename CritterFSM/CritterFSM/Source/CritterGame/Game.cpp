#include "Game.h"
#include "Critter.h"
#include "CritterFinalStateMachine.h"
#include <iostream>
#include <string>

Game::Game()
{
	CritterPet = new Critter();
	bIsRunning = true;
}

Game::~Game()
{
	delete CritterPet;
}

void Game::Startup()
{
	std::cout << "Welcome to the Critter game!" << std::endl;
	std::cout << "Please look after you new pet!" << std::endl;
	std::cout << "What do you want to do with you pet" << std::endl;
	std::cout << "1. Ignore your critter" << std::endl;
	std::cout << "2. Feed your critter" << std::endl;
	std::cout << "3. Play with your critter" << std::endl;
	std::cout << "4. Exit game" << std::endl;
}

std::string Game::GetUserInput(std::string Input)
{
	std::cin >> Input;
	return Input;
}

void Game::Run()
{
	Startup();

	while (bIsRunning)
	{
		std::string UserInput;
		EvaluateUserInput(GetUserInput(UserInput));
		
		std::cout << "Critter Hunger: " << CritterPet->GetHunger() << std::endl;

		CritterPet->IncreaseHunger();
		CritterPet->GetStateMachine()->Update();
	}
}

void Game::EvaluateUserInput(std::string Input)
{
	if (Input == "1")
	{
		std::cout << "You ignored your critter pet." << std::endl;
	}
	else if (Input == "2")
	{
		std::cout << "You feed your critter pet." << std::endl;
		CritterPet->ReduceHunger();
	}
	else if (Input == "3")
	{
		std::cout << "You played with your critter." << std::endl;
	}
	else if (Input == "4")
	{
		std::cout << "Bye!" << std::endl;
		bIsRunning = false;
	}
}
