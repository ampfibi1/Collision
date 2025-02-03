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
	enemy.setOutlineColor(sf::Color::Red);
	enemy.setOutlineThickness(3.f);

	if (font.loadFromFile("Asset/arial.ttf")) {
		printf("Font Load\n");
		text.setFont(font);
		font_position = enemy.getPosition() - sf::Vector2f(40.f,50.f);
		text.setPosition(font_position);
		text.setString("HP :" + std::to_string(int(health)));
		text.setFillColor(sf::Color::Red);
		text.setScale(sf::Vector2f(.75, .75));
	}
	else  printf("Font Not Load\n");
}

void Enemy::update(bool checkCollision, float delta_time)
{
	position = enemy.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) position.x += (delta_time * enemy_speed);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  position.x -= (delta_time * enemy_speed);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    position.y -= (delta_time * enemy_speed);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  position.y += (delta_time * enemy_speed);
	enemy.setPosition(position);
	font_position = enemy.getPosition() - sf::Vector2f(40.f, 50.f);
	text.setPosition(font_position);

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
		text.setString("HP :" + std::to_string(int(health)));
		//std::cout << "Enemy Health : " << health << "\n"; 
	}
}

void Enemy::draw(sf::RenderWindow& window)
{
	if (isAlive) {
		window.draw(enemy);
		window.draw(text);
	}
}