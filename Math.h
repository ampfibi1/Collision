#pragma once
#include<SFML/Graphics.hpp>

class Math
{
public:
	static bool collisionDetector(sf::Vector2f p, sf::Vector2f e);
	static sf::Vector2f normalization(sf::Vector2f dir);
};