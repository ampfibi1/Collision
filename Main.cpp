#include<iostream>
#include "Math.h"

int main() {
	sf::ContextSettings settings; 
	settings.antialiasingLevel = 10; 
	sf::RenderWindow window(sf::VideoMode(1080, 740), "Collision",sf::Style::Default,settings); 

	Player player; 
	player.initialize();
	player.load();
	std::cout << player.getPosition().x+50 << "\n"; 

	Enemy enemy; 
	enemy.initialize();
	enemy.load();

	sf::Vector2f prePlayerPostion = player.getPosition() , preEnemyPosition = enemy.getPosition();

	bool checkCollision = false; 

	while (window.isOpen()) {
		sf::Event event; 
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
		
		player.update(checkCollision,enemy);
		enemy.update(checkCollision);
		checkCollision = Math::collisionDetector(player, enemy);
		
		window.clear(sf::Color::Black);
		player.draw(window);
		enemy.draw(window);
		window.display();
	}
}