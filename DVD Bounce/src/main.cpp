#include "game.h"
#include <iostream>

#define WINDOW_WIDTH sf::VideoMode::getDesktopMode().width
#define WINDOW_HEIGHT sf::VideoMode::getDesktopMode().height

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "DVD Logo", sf::Style::Default);
	window.setFramerateLimit(60);

	sf::RectangleShape rectangle(sf::Vector2f(400, 200));
	sf::Texture logo;
	if (!logo.loadFromFile("D:/Code/C++/DVD Bounce/Textures/dvd-logo-1.jpg"))
	{
		return EXIT_FAILURE;
	}
	logo.setSmooth(true);
	rectangle.setTexture(&logo);
	rectangle.setPosition(100, 200);

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type  == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		
			if (evnt.type == sf::Event::Resized)
			{
				window.setView(sf::View(sf::FloatRect(0, 0, evnt.size.width, evnt.size.height)));
			}
		
		}

		Update(window, rectangle);
		Draw(window, rectangle);
	}
}