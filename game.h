#pragma once
#pragma warning(disable : 4996)

#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "window.h"
#include "settings.h"

#include "StringCrypter.h"

#include <time.h>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>



class Game
{
private:
	//Czy ekran ³adowania ma zostaæ za³adowany
	bool loadLoadingScreen;

	//Tekstura ekranu ³adowania
	sf::Texture loadingTexture;

	//Ekran ³adowania
	sf::Sprite loadingScreen;
	
	//Tekst numeru poziomu
	sf::Text stageText;

	//Nowa gra plus
	int newGamePlus;

	//Buffer dŸwiêku pocisku
	sf::SoundBuffer projectileBuffer;

	//DŸwiêk pocisku
	sf::Sound projectileSound;

	//Czy animacja œmierci ma zostaæ odtworzona
	bool death_animation;

	//Czy królowa zosta³a pokonana
	bool queen_defeated;

	//Czy przeciwnik zosta³ usuniety z pamiêci
	bool enemy_deleted;

	//Tekstura przy œmierci gracza
	sf::Texture playerDeathTexture;

	//Sprite przy œmierci gracza
	sf::Sprite playerDeathImage;

	//Tekstura przy œmierci przeciwnika
	sf::Texture bloodTexture;

	//Sprite przy œmierci przeciwnika
	sf::Sprite zergBloodSplash;

	//Sprawdza czy jest koniec gry
	bool gameOver;

	//Track 1
	sf::SoundBuffer terran1;

	//Muzyka w tle
	sf::Sound backgrundMusic;

	//Buffer dla dŸwiêku œmierci królowej
	sf::SoundBuffer queenDeathBuffer;

	//DŸwiêk œmierci królowej
	sf::Sound queenDeath;

	//Buffer dla dŸwiêku œmierci przeciwnika
	sf::SoundBuffer zergDeathBuffer;

	//DŸwiêk œmierci przeciwnika
	sf::Sound zergDeath;

	//Buffer dla dŸwiêku eksplozji
	sf::SoundBuffer explosionBuffer;

	//DŸwiêk eksplozji
	sf::Sound explosion;

	//Buffer dla dŸwiêku œmierci gracza
	sf::SoundBuffer playerEatenAliveBuffer;

	//DŸwiêk œmierci gracza
	sf::Sound playerEatenAlive;

	//Buffer dla dŸwiêku œmierci gracza
	sf::SoundBuffer playerDeathBuffer;

	//DŸwiêk œmierci gracza
	sf::Sound playerDeath;

	//Królowa leci w prawo
	bool right;

	//Królowa leci w lewo
	bool left;

	//Aktualny licznik do spawnu królowej
	float spawnTimer;

	//Czas potrzebny do spawnu królowej
	float spawnTimerMax;

	//Poziom trudnoœ
	float difficulty;

	//Kierunek ruchu
	float direction;

	//Punkty
	unsigned points;

	//Sterowanie

	//Ruch w lewo
	sf::Keyboard::Key goLeft;

	//Ruch w prawo
	sf::Keyboard::Key goRight;

	//Strza³
	sf::Keyboard::Key shoot;

	//GUI

	//Tekst do pliku
	sf::String saveToFile;

	//Czcionka
	sf::Font font;

	//Tekst dla punktów
	sf::Text pointText;

	//Tekst dla przeciwników
	sf::Text enemiesLeft;

	//Tekst po przegraniu gry
	sf::Text gameOverText;

	//Tekstury
	std::map<std::string, sf::Texture*> textures;

	//Pociski gracza
	std::vector<Bullet*> playerBullets;

	//Pociski przeciwników
	std::vector<Bullet*> enemyBullets;
	
	//Gracz
	Player *player;

	//Tekstura hp
	sf::Texture hpTexture;

	//Ikonka hp1
	sf::Sprite hpSymbol1;

	//Ikonka hp2
	sf::Sprite hpSymbol2;

	//Ikonka hp3
	sf::Sprite hpSymbol3;

	//Przeciwnicy
	std::vector<Enemy*> enemies;

	//Królowa
	Enemy* queen;

	//T³o
	sf::Sprite background;

	//Tekstura t³a
	sf::Texture backgroundTexture;

	//Inicjalizacja okna
	void initWindow(float width, float height);

	//Inicjalizacja interfejsu
	void initGUI(float width, float height);

	//Inicjalizacja sterowania
	void initSettings(sf::Keyboard::Key , sf::Keyboard::Key , sf::Keyboard::Key );

	//Inicjalizacja tekstur
	void initTextures(float width, float height);

	//Inicjalizacja dŸwiêku
	void initAudio(float width, float height);

	//Inicjalizacja gracza
	void initPlayer(float width, float height);

	//Inicjalizacja przeciwnika
	void initEnemies(float width, float height);

	//Inicjalizacja œwiata
	void initWorld(float width, float height);

public:

	Game();

	//Konstruktor
	Game(float width, float height, sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key shoot);

	//Destruktor
	~Game();

	//Metody dostêpu

	//Zwraca aktualny stan zdrowia gracza;
	int& getPlayerHp();

	//Zwraca czy przeciwnicy dotarli do gracza
	bool getGameOver();

	//Zwraca tekst do pliku
	void getContentToFile();

	//Metody

	//Po zabiciu wszystkich przeciwników spawnuje ich na nowo
	void spawnEnemies(float width, float height);

	//Spawnuje królow¹
	void spawnQueen(float width, float height);
	
	//Sprawdza czy okno jest uruchomione
	bool running();

	//Aktualizacja interfejsu
	void updateGUI(float width, float height);

	//Kontrolowanie postaci
	void updatePlayerInput(float width, float height);

	//Kolizja z granic¹ mapy
	void updatePlayerCollision(float width, float height);

	//Atualizacja pocisków
	void updateBullets(float width, float height);

	//Aktualizacja przeciwników
	void updateEnemies(float width, float height);

	//Aktualizacja systemu walki
	void updateCombat(float width, float height);

	//Aktualizujê stan zdrowia gracza
	void updateHp(float width, float height);

	//Aktualizowanie obiektów
	void update(float width, float height);

	//Renderuje interfejs
	void renderGUI(sf::RenderWindow* target);

	//Renderowanie obiektów na ekranie
	void render(sf::RenderWindow& target);
};

