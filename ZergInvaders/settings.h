#pragma once

#include <fstream>

#include <vector>
#include <string>
#include <sstream>
#include <map>

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#define MAX_NUMBER_OF_OPTIONS 7

class Settings
{
private:
	
	//T³o
	sf::Sprite background;

	//Tekstura t³a
	sf::Texture backgroundTexture;

	//Wybrana opcja w menu
	int mainMenuSelected;

	//Czcionka
	sf::Font font;

	//Tekst w ustawieniach
	sf::Text choose[MAX_NUMBER_OF_OPTIONS];

	//Mapowanie przycisków
	std::map<std::string, sf::Keyboard::Key> keyMap;

	//Ruch w lewo
	sf::Keyboard::Key goLeft;

	//Ruch w prawo
	sf::Keyboard::Key goRight;

	//Strzelanie
	sf::Keyboard::Key shoot;

	//Inicjalizacja sterowania
	void initControls();

	//Inicjalizacja UI
	void initSettingsUI(float width, float height);

	//Zamiana sf::Keyboard::Key na std::string
	std::string keyToString(sf::Keyboard::Key key);

	//Zapisuje nowy przycisk do pliku
	void saveKeyToFile(const std::string& filename, sf::Keyboard::Key key);

public:

	Settings();

	//Konstruktor
	Settings(float width, float height);

	//Destruktor
	~Settings();

	//Ustawienie ruchu w lewo
	void setLeft(sf::Keyboard::Key key);

	//Ustawienie ruchu w prawo
	void setRight(sf::Keyboard::Key key);

	//Ustawienie strzelania
	void setShoot(sf::Keyboard::Key key);

	//Zwraca ruch w lewo
	sf::Keyboard::Key getLeft();

	//Zwraca ruch w prawo
	sf::Keyboard::Key getRight();

	//Zwraca strzelanie
	sf::Keyboard::Key getShoot();

	//Ruch w górê w menu
	void moveUp();

	//Ruch w dó³ w menu
	void moveDown();

	//Przycisk wciœniêty w menu
	int mainMenuPressed();

	//Aktualizacja
	void update();

	//Renderowanie
	void render(sf::RenderWindow& target);
};

