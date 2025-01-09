#include "player.h"
#include<iostream>

void Player::initialize()
{
	//std::cout << "Shape Type : "; std::cin >> shape; 
	player = sf::CircleShape(50.f, shape);
}

void Player::load()
{
	player.setFillColor(sf::Color::White);
	player.setRotation(45);
	player.setPosition(sf::Vector2f(540, 370));
}

void Player::update(bool checkCollision)
{
	position = player.getPosition(); 
	if (checkCollision) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) position.x-=50;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) position.x+=50;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) position.y+=50;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) position.y-=50;
	}
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) position.x++;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) position.x--;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) position.y--;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) position.y++;
	}
	player.setPosition(position);
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(player);
}

sf::Vector2f Player::getPosition()
{
	return player.getPosition();
}
