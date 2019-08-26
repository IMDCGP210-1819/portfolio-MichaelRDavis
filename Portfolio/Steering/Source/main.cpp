#include <memory>
#include <iostream>
#include "AI/GameApp.h"

int main()
{
	try
	{
		std::unique_ptr<GameApp> app = std::make_unique<GameApp>();
		app->Init();

		while (!app->GetIsShutdown())
		{
			app->Update();
		}

		app->Shutdown();

	}
	catch (const std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
	}

	return 0;
}