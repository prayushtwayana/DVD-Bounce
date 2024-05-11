#include "game.h"
#include <iostream>

#define WINDOW_WIDTH sf::VideoMode::getDesktopMode().width
#define WINDOW_HEIGHT sf::VideoMode::getDesktopMode().height

sf::Vector2f fileReadRectCoOrd(const std::string fileName)
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

void fileWriteRectCoOrd(const std::string fileName, sf::Vector2f coOrd)
{
	std::ofstream fout;
	fout.open(fileName);

	if (!fout.is_open())
	{
		std::cout << "ERROR LOADING FILE" << std::endl;
		exit(1);
	}

	fout << coOrd.x << " " << coOrd.y << std::endl;

	fout.close();

	if (fout)
	{
		std::cout << "Last Co-ordinates of the Sprite successfully written to file" << std::endl;
	}
	else
	{
		std::cout << "The Co-ordinates could not be written to the file" << std::endl;
	}
	
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "DVD Logo", sf::Style::Default);
	window.setFramerateLimit(60);

	sf::RectangleShape rectangle(sf::Vector2f(400, 200));
	sf::Texture logo;
	if (!logo.loadFromFile("D:/Code/C++/Personal Projects/DVD Bounce/Textures/dvd-logo-1.jpg"))
	{
		return EXIT_FAILURE;
	}
	logo.setSmooth(true);
	rectangle.setTexture(&logo);
	

	sf::Vector2f prevCoOrd = fileReadRectCoOrd(coOrdFile);

	if (prevCoOrd.x && prevCoOrd.y)
		rectangle.setPosition(prevCoOrd.x, prevCoOrd.y);
	else
		rectangle.setPosition(200, 200);


	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type  == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				fileWriteRectCoOrd(coOrdFile, rectangle.getPosition());
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

	return 0;
}