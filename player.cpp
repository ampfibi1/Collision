#include "player.h"

Player::Player() : player_speed(1000.f)
{
}

Player::~Player() 
{
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
	
	player.setPosition(sf::Vector2f(140, 170));
	player.setOrigin(30,30);
}

void Player::update(bool checkCollision,Enemy &enemy, sf::Vector2f& mouse_pos, float delta_time)
{
	position = player.getPosition(); 
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) position.x+= (delta_time * player_speed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) position.x-= (delta_time * player_speed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) position.y-= (delta_time * player_speed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) position.y+= (delta_time * player_speed);
	}
	player.setPosition(position);


	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (clock.getElapsedTime().asSeconds() > .1f) {
			bulletss.push_back(Bullet());

			int i = bulletss.size() - 1 ;

			bulletss[i].initialize(position, mouse_pos);
			clock.restart();
		}
	}
	for (int i = 0; i < bulletss.size(); ++i) {
		bulletss[i].update(delta_time);
	}


	////delete bullets after hit the target
	for (int i = 0; i < bulletss.size(); ++i) {
		if (Math::collisionDetector(enemy.getPosition(), bulletss[i].getPosition())) {
			bulletss.erase(bulletss.begin() + i--);
			enemy.collapse_with_bullets(true);
		}
	}
}

void Player::draw(sf::RenderWindow& window)
{
	//for (auto x : bullets) window.draw(x);
	for (auto x : bulletss) x.draw(window);
	window.draw(player);
}

sf::Vector2f Player::getPosition()
{
	return player.getPosition();
}
