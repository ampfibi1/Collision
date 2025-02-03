#include<iostream>
#include <cmath> 
#include "Math.h"
#include"player.h"
#include"FPS.h"

int main() {
	sf::ContextSettings settings; 
	settings.antialiasingLevel = 10; 
	sf::RenderWindow window(sf::VideoMode(1080, 740), "Collision",sf::Style::Default,settings); 

	window.setFramerateLimit(120);
	bool checkCollision = false;
	sf::Clock Timer;
	sf::Time delta_timer;
	float delta_time;
	Player player; 

	player.initialize();
	player.load();
	std::cout << player.getPosition().x+50 << "\n"; 

	Enemy enemy; 
	enemy.initialize();
	enemy.load();

	FPS fps; 
	fps.initialize();
	fps.load();

	sf::Vector2f prePlayerPostion = player.getPosition() , preEnemyPosition = enemy.getPosition();





	sf::RectangleShape gun(sf::Vector2f(20,100));
	gun.setFillColor(sf::Color::Red);
	gun.setPosition(player.getPosition());
	gun.setOrigin(sf::Vector2f(10, 0));

 // For atan2

	 // Vector from gun to mouse



	while (window.isOpen()) {
		sf::Event event; 
		delta_timer = Timer.restart(); 
		delta_time = delta_timer.asSeconds();

		//printf("%f\n",1/delta_time);
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
		
		sf::Vector2f mouse_pos = sf::Vector2f(sf::Mouse::getPosition(window));

		sf::Vector2f direction = mouse_pos - gun.getPosition();
		//float mag = sqrt(direction.x * direction.x + direction.y * direction.y);
		//float angle = asinf(direction.y/ mag) * 180 /3.14159; 
		float angle = atan2(direction.y, direction.x) * 180 / 3.14159; // Convert radians to degrees
		gun.setRotation(angle-90);

		// Inside the game loop, before window.clear():
		gun.setPosition(player.getPosition().x , player.getPosition().y + 30); // Adjust as needed


		player.update(checkCollision,enemy,mouse_pos,delta_time);
		enemy.update(checkCollision, delta_time);
		checkCollision = Math::collisionDetector(player.getPosition(), enemy.getPosition());
		fps.update(delta_time);
		
		window.clear(sf::Color::Black);
		window.draw(gun);
		player.draw(window);
		enemy.draw(window);
		fps.draw(window);
		
		window.display();
	}
}