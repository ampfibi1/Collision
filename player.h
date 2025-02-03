#pragma once
#include"Enemy.h"
#include"Bullet.h"
//#include"Math.h"

class Player
{
private:
	sf::CircleShape player; 
	sf::Vector2f position; 
	int shape = 4; 
	//std::vector<sf::CircleShape> bullets; 
	sf::Vector2f bulletDirection;
	sf::Clock clock; 

	std::vector<Bullet> bulletss;
	float player_speed; 
public:
	Player();
	~Player();

	void initialize();
	void load();
	void update(bool checkCollision,
			Enemy &enemy,
			sf::Vector2f& mouse_pos,
			float delta_time);
	void draw(sf::RenderWindow &window);
	sf::Vector2f getPosition();
};