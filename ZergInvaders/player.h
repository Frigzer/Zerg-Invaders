#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Player
{
private:

	//Aktualna warto�� �ycia gracza
	int hp;

	//Maksymalna warto�� �ycia
	int hpMax;

	//Pr�dko�� poruszania si�
	float movementSpeed;

	//Aktualny cooldown
	float attackCooldown;

	//Czas pomi�dzy kt�rym mo�na atakowa�
	float attackCooldownMax;

	//Gracz
	sf::Sprite player;

	//Tekstura gracza
	sf::Texture texture;

	//Inicjalizacja gracza
	void initPlayer();

public:

	//Konstruktor
	Player();

	//Destruktor
	~Player();
	
	//Metody

	//Rozmiar gracza
	sf::FloatRect getPlayerBounds();

	//Pobiera pozycja gracza
	sf::Vector2f getPlayerPosition();

	//Modyfikuje pozycje gracza
	void setPlayerPosition(float x, float y);

	void setHp(int value);

	//Poruszanie si�
	void move(float x, float y);

	//Czy gracz mo�e atakowa�
	bool canAttack();

	//Aktualizuje czas ataku
	void updateAttack();

	//Zwraca warto�� hp
	int& getHp();

	//Zwraca maksymaln� warto�� hp
	int& getHpMax();

	//Zmniejsza warto�� hp
	void loseHp(int damage);

	//Aktualizowanie gracza
	void update();

	//Renderowanie gracza
	void render(sf::RenderTarget* target);
};

