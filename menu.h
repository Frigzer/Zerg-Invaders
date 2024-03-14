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

	//Tytu³ w menu
	sf::Text menuTitle;

	//T³o
	sf::Sprite background;

	//Tekstura t³a
	sf::Texture backgroundTexture;

public:
	Menu();

	//Konstruktor
	Menu(float width, float height);

	//Destruktor
	~Menu();

	//Odtwarza muzykê w menu
	void musicPlay();

	//Zatrzymuje muzykê w menu
	void musicStop();

	//renderowanie
	void render(sf::RenderWindow& target);

	//Poruszanie siê w górê w menu
	void moveUp();

	//Poruszanie siê w dó³ w menu
	void moveDown();

	//Wciœniêty przycisk w menu
	int mainMenuPressed();
};

