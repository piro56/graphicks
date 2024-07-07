#include "Game.h"

void Game::initVars()
{
	this->window = nullptr;
	this->window_title = "Hello World";

	circle_sz = 100.;

}

void Game::initWindow()
{
	this->videomode.height = INIT_WINDOW_HEIGHT;
	this->videomode.width = INIT_WINDOW_WIDTH;
	this->window = new sf::RenderWindow(this->videomode, this->window_title);
}

void Game::initSprites()
{

}


Game::Game()
{
	this->initVars();
	this->initWindow();
	this->initSprites();
}

Game::~Game()
{
	delete this->window;
}

void Game::pollEvents() {
	if (!window) return;
	sf::Event event;
	while (this->window->pollEvent(event))
	{
		switch (event.type) {
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code) {
					case sf::Keyboard::Escape:
						this->window->close();
						break;
					case sf::Keyboard::A:
						this->circle_sz++;
						break;
				}
		}
	}
}
void Game::update() {
	this->pollEvents();

}

void Game::render() {
	window->clear();
	window->draw(sf::CircleShape(this->circle_sz));
	window->display();
}

void Game::run() {
	while (this->isWindowOpen()) {
		this->update();
		this->render();
	}
}

const bool Game::isWindowOpen() const
{
	if (!this->window) return false;
	return this->window->isOpen();
}
