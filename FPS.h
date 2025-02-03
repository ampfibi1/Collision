#pragma once
#include<SFML/Graphics.hpp>

class FPS
{
private:
	sf::Font fps_font; 
	sf::Text fps_text; 
	int fps;
	sf::Clock fps_clock; 
	float max_fps_clock; 
public:
	FPS();
	~FPS();

	void initialize();
	void load();
	void update(float delta_time);
	void draw(sf::RenderWindow &window);
};