#include "window.h"

void Window::initWindow()
{
	
}

Window::Window()
{
	videoMode.width = 900;
	videoMode.height = 940;
	window = new sf::RenderWindow(videoMode, "Zerg Invaders", sf::Style::Titlebar | sf::Style::Close);
	if (!image.loadFromFile("Textures/TerranDominionLogo.png"))
		std::cout << "!ERROR::GAME::INIWINDOW::Nie mozna zaladowac ikonki." << std::endl;
	window->setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(false);
	
}

Window::~Window()
{
}

sf::RenderWindow* Window::getWindow()
{
	return window;
}


