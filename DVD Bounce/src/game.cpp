#pragma once
#include "game.h"
#include <iostream>

void colorChange(sf::RectangleShape& rectangle, int &index)
{
	if (index == 6)
	{
		index = 0;
	}

	switch (index)
	{
	case 0:
		rectangle.setFillColor(sf::Color(0, 254, 255));
		break;

	case 1:
		rectangle.setFillColor(sf::Color(190, 0, 255));
		break;

	case 2:
		rectangle.setFillColor(sf::Color(255, 250, 1));
		break;

	case 3:
		rectangle.setFillColor(sf::Color(190, 0, 255));
		break;

	case 4:
		rectangle.setFillColor(sf::Color(255, 131, 0));
		break;

	case 5:
		rectangle.setFillColor(sf::Color(255, 38, 0));
		break;

	case 6:
		rectangle.setFillColor(sf::Color(255, 0, 139));
		break;
	}

	index++;
}

void Update(sf::RenderWindow& window, sf::RectangleShape& rectangle)
{
	static int index;
	
	static float Xoffset = 5;
	static float Yoffset = 5;

	rectangle.move(Xoffset, Yoffset);

	if (rectangle.getPosition().x >= window.getSize().x - rectangle.getSize().x || rectangle.getPosition().x == 0)
	{
		colorChange(rectangle, index);
		Xoffset = -Xoffset;
	}

	if (rectangle.getPosition().y >= window.getSize().y - rectangle.getSize().y || rectangle.getPosition().y == 0)
	{
		colorChange(rectangle, index);
		Yoffset = -Yoffset;
	}
}

void Draw(sf::RenderWindow& window, sf::RectangleShape& rectangle)
{
	window.clear();
	window.draw(rectangle);
	window.display();
}