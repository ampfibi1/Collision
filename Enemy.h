#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string.h>

class Enemy
{
private:
	sf::CircleShape enemy; 
	sf::Vector2f position;
	int shape = 4;
	float health ;
	bool isAlive ; 
	
	//std::vector<sf::CircleShape> enemys;
	int gen_x , gen_y;
	int last; 

	sf::Text text; 
	sf::Font font;
	sf::Vector2f font_position;

	float enemy_speed = 1000.f;
	
public:

	void initialize();
	void load();
	void update(bool checkCollision,float delta_time);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
	void collapse_with_bullets(bool is_enmy_collapse_with_bullets);
};