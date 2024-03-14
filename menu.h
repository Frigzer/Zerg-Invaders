#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#define MAX_NUMBER_OF_ITEMS 4

class Menu
{
private:

	//Buffer do muzyki w menu
	sf::SoundBuffer menuMusicBuffer;

	//Muzyka w menu
	sf::Sound menuMusic;

	//Wybrana opcja w menu
	int mainMenuSelected;

	//Czcionka
	sf::Font font;

	//Tekst w menu
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

	//Tytu� w menu
	sf::Text menuTitle;

	//T�o
	sf::Sprite background;

	//Tekstura t�a
	sf::Texture backgroundTexture;

public:
	Menu();

	//Konstruktor
	Menu(float width, float height);

	//Destruktor
	~Menu();

	//Odtwarza muzyk� w menu
	void musicPlay();

	//Zatrzymuje muzyk� w menu
	void musicStop();

	//renderowanie
	void render(sf::RenderWindow& target);

	//Poruszanie si� w g�r� w menu
	void moveUp();

	//Poruszanie si� w d� w menu
	void moveDown();

	//Wci�ni�ty przycisk w menu
	int mainMenuPressed();
};

