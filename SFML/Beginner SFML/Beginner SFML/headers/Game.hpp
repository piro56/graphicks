#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "MyBox2D.hpp"

class Game
{
private:
	
	sf::RenderWindow* window;
	sf::VideoMode videomode;

	std::vector<sf::Drawable*> drawables;

	MyBox2D physics;

	void initVars();
	void initWindow();
	void initSprites();
	void initPhysics();
	
	double rect_width;



	
public:
	const float INIT_WINDOW_HEIGHT = 800.0f;
	const float INIT_WINDOW_WIDTH = 800.0f;
	
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

