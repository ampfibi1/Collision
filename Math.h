#pragma once
#include"player.h"
#include"Enemy.h"
class Math
{
public:
	static bool collisionDetector(Player p, Enemy e);
	//static sf::Vector2f normalization(sf::Vector2f dir);
};