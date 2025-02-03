#include "Math.h"
//#include<iostream>

bool Math::collisionDetector(sf::Vector2f p, sf::Vector2f e)
{
		bool f = false;

		float playerSize = 70.0f, enemySize = 70.0f;

		if (
			(e.x < p.x + playerSize && e.x + enemySize > p.x) &&
			(e.y < p.y + playerSize && e.y + enemySize > p.y)
			) {
			//std::cout << "Player And Enemy Collision.\n";
			f = true;
		}
		return f;
	
}

sf::Vector2f Math::normalization(sf::Vector2f dir)
{
	float mag = sqrt(dir.x * dir.x + dir.y * dir.y);
	if (!mag) return sf::Vector2f(0, 0);
	return dir / mag;
}
