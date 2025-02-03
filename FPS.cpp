#include "FPS.h"

FPS::FPS() : fps(0) , max_fps_clock(1.f)
{
}

FPS::~FPS()
{
}

void FPS::initialize()
{
}

void FPS::load()
{
	if (fps_font.loadFromFile("Asset/arial.ttf")) {
		printf("Font Load\n");
		fps_text.setFont(fps_font);
		fps_text.setFillColor(sf::Color::Green);
		fps_text.setString("Fps :" + std::to_string(fps));
	}
	else printf("Font Not Load\n");
}

void FPS::update(float delta_time)
{
	fps = 1 / delta_time;
	if (fps_clock.getElapsedTime().asSeconds() >= max_fps_clock) {
		fps_text.setString("Fps :" + std::to_string(fps));
		fps_clock.restart();
	}
}

void FPS::draw(sf::RenderWindow& window)
{
	window.draw(fps_text); 
}
