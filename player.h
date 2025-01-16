#pragma once
#include"Enemy.h"
//#include"Math.h"

class Player
{
private:
	sf::CircleShape player; 
	sf::Vector2f position; 
	int shape = 4; 
	std::vector<sf::CircleShape> bullets; 
	sf::Vector2f bulletDirection;
	sf::Clock clock; 

	sf::Vector2f normalization(sf::Vector2f dir);
public:
	void initialize();
	void load();
	void update(bool checkCollision,Enemy enemy);
	void draw(sf::RenderWindow &window);
	sf::Vector2f getPosition();
};