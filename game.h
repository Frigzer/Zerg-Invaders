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
	//Czy ekran �adowania ma zosta� za�adowany
	bool loadLoadingScreen;

	//Tekstura ekranu �adowania
	sf::Texture loadingTexture;

	//Ekran �adowania
	sf::Sprite loadingScreen;
	
	//Tekst numeru poziomu
	sf::Text stageText;

	//Nowa gra plus
	int newGamePlus;

	//Buffer d�wi�ku pocisku
	sf::SoundBuffer projectileBuffer;

	//D�wi�k pocisku
	sf::Sound projectileSound;

	//Czy animacja �mierci ma zosta� odtworzona
	bool death_animation;

	//Czy kr�lowa zosta�a pokonana
	bool queen_defeated;

	//Czy przeciwnik zosta� usuniety z pami�ci
	bool enemy_deleted;

	//Tekstura przy �mierci gracza
	sf::Texture playerDeathTexture;

	//Sprite przy �mierci gracza
	sf::Sprite playerDeathImage;

	//Tekstura przy �mierci przeciwnika
	sf::Texture bloodTexture;

	//Sprite przy �mierci przeciwnika
	sf::Sprite zergBloodSplash;

	//Sprawdza czy jest koniec gry
	bool gameOver;

	//Track 1
	sf::SoundBuffer terran1;

	//Muzyka w tle
	sf::Sound backgrundMusic;

	//Buffer dla d�wi�ku �mierci kr�lowej
	sf::SoundBuffer queenDeathBuffer;

	//D�wi�k �mierci kr�lowej
	sf::Sound queenDeath;

	//Buffer dla d�wi�ku �mierci przeciwnika
	sf::SoundBuffer zergDeathBuffer;

	//D�wi�k �mierci przeciwnika
	sf::Sound zergDeath;

	//Buffer dla d�wi�ku eksplozji
	sf::SoundBuffer explosionBuffer;

	//D�wi�k eksplozji
	sf::Sound explosion;

	//Buffer dla d�wi�ku �mierci gracza
	sf::SoundBuffer playerEatenAliveBuffer;

	//D�wi�k �mierci gracza
	sf::Sound playerEatenAlive;

	//Buffer dla d�wi�ku �mierci gracza
	sf::SoundBuffer playerDeathBuffer;

	//D�wi�k �mierci gracza
	sf::Sound playerDeath;

	//Kr�lowa leci w prawo
	bool right;

	//Kr�lowa leci w lewo
	bool left;

	//Aktualny licznik do spawnu kr�lowej
	float spawnTimer;

	//Czas potrzebny do spawnu kr�lowej
	float spawnTimerMax;

	//Poziom trudno�
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

	//Strza�
	sf::Keyboard::Key shoot;

	//GUI

	//Tekst do pliku
	sf::String saveToFile;

	//Czcionka
	sf::Font font;

	//Tekst dla punkt�w
	sf::Text pointText;

	//Tekst dla przeciwnik�w
	sf::Text enemiesLeft;

	//Tekst po przegraniu gry
	sf::Text gameOverText;

	//Tekstury
	std::map<std::string, sf::Texture*> textures;

	//Pociski gracza
	std::vector<Bullet*> playerBullets;

	//Pociski przeciwnik�w
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

	//Kr�lowa
	Enemy* queen;

	//T�o
	sf::Sprite background;

	//Tekstura t�a
	sf::Texture backgroundTexture;

	//Inicjalizacja okna
	void initWindow(float width, float height);

	//Inicjalizacja interfejsu
	void initGUI(float width, float height);

	//Inicjalizacja sterowania
	void initSettings(sf::Keyboard::Key , sf::Keyboard::Key , sf::Keyboard::Key );

	//Inicjalizacja tekstur
	void initTextures(float width, float height);

	//Inicjalizacja d�wi�ku
	void initAudio(float width, float height);

	//Inicjalizacja gracza
	void initPlayer(float width, float height);

	//Inicjalizacja przeciwnika
	void initEnemies(float width, float height);

	//Inicjalizacja �wiata
	void initWorld(float width, float height);

public:

	Game();

	//Konstruktor
	Game(float width, float height, sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key shoot);

	//Destruktor
	~Game();

	//Metody dost�pu

	//Zwraca aktualny stan zdrowia gracza;
	int& getPlayerHp();

	//Zwraca czy przeciwnicy dotarli do gracza
	bool getGameOver();

	//Zwraca tekst do pliku
	void getContentToFile();

	//Metody

	//Po zabiciu wszystkich przeciwnik�w spawnuje ich na nowo
	void spawnEnemies(float width, float height);

	//Spawnuje kr�low�
	void spawnQueen(float width, float height);
	
	//Sprawdza czy okno jest uruchomione
	bool running();

	//Aktualizacja interfejsu
	void updateGUI(float width, float height);

	//Kontrolowanie postaci
	void updatePlayerInput(float width, float height);

	//Kolizja z granic� mapy
	void updatePlayerCollision(float width, float height);

	//Atualizacja pocisk�w
	void updateBullets(float width, float height);

	//Aktualizacja przeciwnik�w
	void updateEnemies(float width, float height);

	//Aktualizacja systemu walki
	void updateCombat(float width, float height);

	//Aktualizuj� stan zdrowia gracza
	void updateHp(float width, float height);

	//Aktualizowanie obiekt�w
	void update(float width, float height);

	//Renderuje interfejs
	void renderGUI(sf::RenderWindow* target);

	//Renderowanie obiekt�w na ekranie
	void render(sf::RenderWindow& target);
};

