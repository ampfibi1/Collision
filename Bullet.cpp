#include "Bullet.h"

Bullet::Bullet() : bullet_speed(800.f)
{
}

Bullet::~Bullet()
{
}

void Bullet::initialize(const sf::Vector2f &pos, sf::Vector2f mouse_pos)
{
	shape = sf::CircleShape(10.f);
	shape.setPosition(pos);
	shape.setFillColor(sf::Color::Cyan);
	shape.setRotation(45);

	bullet_direction = Math::normalization(mouse_pos- pos);
	//bullet_speed = 200.f
}

void Bullet::load()
{
}

void Bullet::update(float delta_time)
{
	shape.setPosition(shape.getPosition() + bullet_direction * delta_time * bullet_speed);
	//shape.setPosition(shape.getPosition()+bullet_direction);
}

void Bullet::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

sf::Vector2f Bullet::getPosition()
{
	return shape.getPosition();
}
