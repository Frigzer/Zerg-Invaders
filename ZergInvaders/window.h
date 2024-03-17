#pragma once

#include "enemy.h"
#include "bullet.h"
#include "menu.h"

#include <vector>
#include <string>
#include <sstream>

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Window
{
private:
	//W³aœciwoœci okna
	sf::RenderWindow* window;

	//Rozmiary okna
	sf::VideoMode videoMode;

	//Ikonka okna
	sf::Image image;

	//Inicjalizacja okna
	void initWindow();

public:
	//Konstruktor
	Window();

	//Destruktor
	~Window();

	//Zwraca okno gry
	sf::RenderWindow* getWindow();
};

