#include "Enemy.h"

void Enemy::initialize()
{
	enemy = sf::CircleShape(50.f, shape);
}

void Enemy::load()
{
	enemy.setFillColor(sf::Color::White);
	enemy.setRotation(45);
	enemy.setPosition(sf::Vector2f(540+60, 370));
}

void Enemy::update(bool checkCollision)
{
	position = enemy.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) position.x++;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) position.x--;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) position.y--;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) position.y++;
	enemy.setPosition(position);
}

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(enemy);
}

sf::Vector2f Enemy::getPosition()
{
	return enemy.getPosition();
}