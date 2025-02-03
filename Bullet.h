#pragma once
#include<SFML/Graphics.hpp>
#include"Math.h"

class Bullet
{
private:
	sf::CircleShape shape;
	sf::Vector2f bullet_direction;
	float bullet_speed; 
public:
	Bullet();
	~Bullet();

	void initialize(const sf::Vector2f &pos, sf::Vector2f mouse_pos);
	void load();
	void update(float delta_time);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
};