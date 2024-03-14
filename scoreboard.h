#pragma once

#include <SFML/Graphics.hpp>

#include <string>

#include <sstream>

#include <iostream>

#include <fstream>

#include "StringCrypter.h"

class Scoreboard
{
private:

	//T³o
	sf::Sprite background;

	//Tekstura t³a
	sf::Texture backgroundTexture;

	//Czcionka
	sf::Font font;

	//Tekst do wyœwietlenia
	sf::Text results;

	//Strumieñ dla tekstu
	std::stringstream resultStream;

	//Inicjalizacja tekstu
	void initText();

public:
	//Konstruktor
	Scoreboard();

	//Destruktor
	~Scoreboard();

	//Renderowanie
	void render(sf::RenderWindow& target);

};

