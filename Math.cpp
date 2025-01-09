#include "Math.h"
#include<iostream>

bool Math::collisionDetector(Player p, Enemy e)
{
		sf::Vector2f ppos = p.getPosition();
		sf::Vector2f epos = e.getPosition();
		bool f = false;

		float playerSize = 70.0f, enemySize = 70.0f;

		if (
			(epos.x < ppos.x + playerSize && epos.x + enemySize > ppos.x) &&
			(epos.y < ppos.y + playerSize && epos.y + enemySize > ppos.y)
			) {
			std::cout << "Collision.\n";
			f = true;
		}
		return f;
	
}
