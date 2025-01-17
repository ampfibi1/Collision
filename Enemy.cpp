#include "Enemy.h"

void Enemy::initialize()
{
	enemy = sf::CircleShape(50.f, shape);
	health = 100; 
}

void Enemy::load()
{
	enemy.setFillColor(sf::Color::White);
	enemy.setRotation(45);
	enemy.setPosition(sf::Vector2f(540+60, 370));
	enemy.setOrigin(30.f, 30.f);
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

void Enemy::collapse_with_bullets(bool is_enmy_collapse_with_bullets)
{
	if (is_enmy_collapse_with_bullets) {
		if (!health) health = health; 
		else health -= 10;
		std::cout << "Enemy Health : " << health << "\n"; 
		
		/*if (!health) {
			enemy = sf::CircleShape(0.f, shape);
		}*/
	}
}
