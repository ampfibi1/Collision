#pragma once
#include<SFML/Graphics.hpp>

class Enemy
{
private:
	sf::CircleShape enemy; 
	sf::Vector2f position;
	int shape = 4;
public:
	void initialize();
	void load();
	void update(bool checkCollision);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
};

