#include "../Source/Graphs/RenderGraphNode.h"
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Graphs");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		RenderGraphNode* renderNode = new RenderGraphNode();
		renderNode->Draw(window);

		window.display();
	}

	return 0;
}