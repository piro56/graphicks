#include "Game.hpp"

void Game::initVars()
{
	this->window = nullptr;
	this->window_title = "Hello World";

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

void Game::initPhysics()
{
	this->physics.init();
}


Game::Game()
{
	this->initVars();
	this->initWindow();
	this->initSprites();
	this->initPhysics();
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
				}
		}
	}
}
void Game::update() {
	this->pollEvents();
	
	physics.simulate();
}

void Game::render() {
	window->clear();
	sf::CircleShape circ(50.);
	sf::RectangleShape rec(sf::Vector2f(100., 100.));
	circ.setPosition(INIT_WINDOW_WIDTH - 100, INIT_WINDOW_HEIGHT - 100);

	b2Vec2 pos = physics.dynamicBody->GetPosition();
	std::cout << pos.x << ", " << pos.y << std::endl;

	rec.setPosition(sf::Vector2f(pos.x * 100, INIT_WINDOW_HEIGHT-pos.y * 100));

	window->draw(rec);
	window->draw(circ);

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

