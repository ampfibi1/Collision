#include "Enemy.h"

void Enemy::initialize()
{
	enemy = sf::CircleShape(50.f, shape);
	health = 100; 
	isAlive = true; 
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

	/*if (!isAlive) {
		enemys.push_back(sf::CircleShape(50.f, shape));
		gen_x = rand() % 1080;
		gen_y = rand() % 740;
		last = enemys.size() - 1;
		std::cout << gen_x << " " << gen_y << std::endl;
		enemys[last].setFillColor(sf::Color::White);
		enemys[last].setRotation(45);
		enemys[last].setPosition(sf::Vector2f(gen_x, gen_y));
		enemys[last].setOrigin(30.f, 30.f);
		isAlive = true; 
	}*/
}

void Enemy::draw(sf::RenderWindow& window)
{
	if (isAlive) {
		window.draw(enemy);
	}
	//for (auto x : enemys) window.draw(x); 
}

sf::Vector2f Enemy::getPosition()
{
	return enemy.getPosition();
}

void Enemy::collapse_with_bullets(bool is_enmy_collapse_with_bullets)
{
	if (is_enmy_collapse_with_bullets) {
		if (!health) {
			isAlive = false;
			gen_x = rand() % 1080;
			gen_y = rand() % 740;
			enemy.setPosition(sf::Vector2f(gen_x, gen_y)); 
			isAlive = true; 
			health = 100; 
		}
		else health -= 10;
		std::cout << "Enemy Health : " << health << "\n"; 
	}
}
