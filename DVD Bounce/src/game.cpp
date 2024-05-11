#pragma once
#include "game.h"
#include <iomanip>
#include <iostream>

void colorChange(sf::RectangleShape& rectangle, int &index)
{
	if (index == 7)
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
		rectangle.setFillColor(sf::Color(255, 131, 0));
		break;

	case 4:
		rectangle.setFillColor(sf::Color(255, 38, 0));
		break;

	case 5:
		rectangle.setFillColor(sf::Color(255, 0, 139));
		break;

	case 6:
		rectangle.setFillColor(sf::Color(13, 233, 3));
		break;
	}

	index++;
}

void fileWriteColorIndex(const std::string fileName, int colorIndex)
{
	std::ofstream fout;
	fout.open(fileName);

	if (!fout.is_open())
	{
		std::cout << "ERROR LOADING FILE" << std::endl;
		exit(1);
	}

	fout << colorIndex << std::endl;

	fout.close();

	if (fout)
	{
		std::cout << "Last Color Index of the Sprite successfully written to file" << std::endl;
	}
	else
	{
		std::cout << "The Color Index could not be written to the file" << std::endl;
	}
}

int fileReadColorIndex(const std::string fileName)
{
	std::ifstream fin;
	fin.open(fileName);

	if (!fin.is_open())
	{
		std::cout << "ERROR LOADING FILE" << std::endl;
	}

	std::string line;
	std::getline(fin, line);

	int color = std::stoi(line);

	return color;
}

void fileWriteOffset(const std::string fileName, sf::Vector2f offset)
{
	std::ofstream fout;
	fout.open(fileName);

	if (!fout.is_open())
	{
		std::cout << "ERROR LOADING FILE" << std::endl;
		exit(1);
	}

	fout << offset.x << " " << offset.y << std::endl;

	fout.close();


	if (fout)
	{
		std::cout << "Last Offset of the Sprite successfully written to file" << std::endl;
	}
	else
	{
		std::cout << "The Offset could not be written to the file" << std::endl;
	}
}

sf::Vector2f fileReadOffset(const std::string fileName)
{
	std::ifstream fin;
	fin.open(fileName);

	if (!fin.is_open())
	{
		std::cout << "ERROR LOADING FILE" << std::endl;
		exit(1);
	}

	std::string line;
	std::getline(fin, line);

	std::stringstream ss(line);
	std::string word;

	sf::Vector2f coOrd;

	int counter = 0;
	while (ss >> word)
	{
		if (counter == 0)
		{
			coOrd.x = std::stof(word);
		}
		else
		{
			coOrd.y = std::stof(word);
		}
		counter++;
	}

	fin.close();

	return coOrd;
}

void Update(sf::RenderWindow& window, sf::RectangleShape& rectangle)
{
	int colorIndex = fileReadColorIndex(colorIndexFile);
	colorChange(rectangle, colorIndex);

	sf::Vector2f offsets = fileReadOffset(offsetFile);

	static float Xoffset = offsets.x;
	static float Yoffset = offsets.y;

	rectangle.move(Xoffset, Yoffset);
	sf::Vector2f pos = rectangle.getPosition();

	sf::Vector2f offset;

	if (rectangle.getPosition().x >= window.getSize().x - rectangle.getSize().x || rectangle.getPosition().x == 0)
	{
		colorChange(rectangle, colorIndex);
		Xoffset = -Xoffset;

		offset.x = Xoffset;
		offset.y = Yoffset;
		fileWriteOffset(offsetFile, offset);
		fileWriteColorIndex(colorIndexFile, colorIndex);
	}

	if (rectangle.getPosition().y >= window.getSize().y - rectangle.getSize().y || rectangle.getPosition().y == 0)
	{
		colorChange(rectangle, colorIndex);
		Yoffset = -Yoffset;

		offset.x = Xoffset;
		offset.y = Yoffset;
		fileWriteOffset(offsetFile, offset);
		fileWriteColorIndex(colorIndexFile, colorIndex);
	}
}

void Draw(sf::RenderWindow& window, sf::RectangleShape& rectangle)
{
	window.clear();
	window.draw(rectangle);
	window.display();
}