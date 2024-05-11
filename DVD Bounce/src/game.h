#pragma once
#include <SFML/Graphics.hpp>
#include <ostream>
#include <fstream>
#include <string>
#include <sstream>

void Update(sf::RenderWindow& window,sf::RectangleShape& rectangle);
void Draw(sf::RenderWindow &window, sf::RectangleShape &rectangle);

void colorChange(sf::RectangleShape& rectangle, int &index);

const std::string coOrdFile = "_coordinates.txt";
const std::string offsetFile = "_offset.txt";
const std::string colorIndexFile = "_colorIndex.txt";
