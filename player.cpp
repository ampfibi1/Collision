#include "player.h"
#include<iostream>

sf::Vector2f Player::normalization(sf::Vector2f dir)
{
	float mag = sqrt(dir.x * dir.x + dir.y * dir.y);
	if (!mag) return sf::Vector2f(0, 0);
	return dir / mag;
}
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

void Player::update(bool checkCollision,Enemy enemy)
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

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (clock.getElapsedTime().asSeconds()> .1f) {
			bullets.push_back(sf::CircleShape(10.f));
			bullets[bullets.size() - 1].setPosition(position);
			bullets[bullets.size() - 1].setFillColor(sf::Color::Cyan);
			clock.restart();
		}
	}

	for (int i = 0; i < bullets.size(); ++i) {
		bulletDirection = enemy.getPosition()-bullets[i].getPosition();
		bulletDirection = normalization(bulletDirection);
		bullets[i].setPosition(bullets[i].getPosition()+bulletDirection);
	}
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(player);
	for (auto x : bullets) window.draw(x);
}

sf::Vector2f Player::getPosition()
{
	return player.getPosition();
}
