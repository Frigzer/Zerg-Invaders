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

	//T�o
	sf::Sprite background;

	//Tekstura t�a
	sf::Texture backgroundTexture;

	//Czcionka
	sf::Font font;

	//Tekst do wy�wietlenia
	sf::Text results;

	//Strumie� dla tekstu
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

