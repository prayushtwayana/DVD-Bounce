#pragma once
#include <SFML/Graphics.hpp>

void Update(sf::RenderWindow& window,sf::RectangleShape& rectangle);
void Draw(sf::RenderWindow &window, sf::RectangleShape &rectangle);

void colorChange(sf::RectangleShape& rectangle, int &index);