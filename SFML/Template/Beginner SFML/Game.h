#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>


class Game
{
private:

	sf::RenderWindow* window;
	sf::VideoMode videomode;

	void initVars();
	void initWindow();
	void initSprites();

	double circle_sz;



public:
	const int INIT_WINDOW_HEIGHT = 800;
	const int INIT_WINDOW_WIDTH = 800;
	
	std::string window_title;




	// Constructors and Destructors
	Game();
	virtual ~Game();

	// Fn
	void pollEvents();

	void update();
	void render();
	void run();

	// Accessors
	const bool isWindowOpen() const;







};

