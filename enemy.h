#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Enemy
{
private:

	//Aktualne punkty �ycia przeciwnika
	int hp;

	//Punkty �ycia maksymalne w danej rundzie
	int hpMax;

	//Punkty
	int points;

	//Pr�dko�� poruszania si�
	float movementSpeed;

	//Aktualny cooldown
	float attackCooldown;

	//Czas pomi�dzy kt�rym mo�na atakowa�
	float attackCooldownMax;

	//Typ przeciwnika
	int type;

	//Typ przeciwnika kt�ry b�dzie zwracany
	int enemyType;

	//Przeciwnik
	sf::Sprite enemy;

	//Tekstura przeciwnika
	sf::Texture texture;

	//Inicjalizacja przeciwnika
	void initEnemy(int type, int stage);

public:

	Enemy();

	//Konstruktor
	Enemy(int stage, int type ,float x, float y);

	//Destruktor
	~Enemy();

	//Metody dost�pu

	//Rozmiar przeciwnika
	sf::FloatRect getEnemyBounds();

	//Pobiera pozycja przeciwnika
	sf::Vector2f getEnemyPosition();

	//Zwracanie typu przeiwnika
	int getEnemyType();

	//Zwraca warto�� hp
	int& getHp();

	//Zwraca maksymaln� warto�� hp
	int& getHpMax();

	void setHp(int value);

	//Zmniejsza warto�� hp
	void loseHp(int damage);

	//Zwraca sprite przeciwnika
	void setEnemyTexture(sf::Texture);

	//Metody

	//Modyfikuje pozycje przeciwnika
	void setEnemyPosition(float x, float y);

	//Poruszanie si�
	void move(float x, float y);

	//Czy przeciwnik mo�e atakowa�
	bool canAttack();

	//Aktualizuje czas ataku
	void updateAttack();

	//Daje punkty
	int& getPoints();

	//Aktualizacja przeciwnika
	void update();

	//Renderowanie;
	void render(sf::RenderTarget* target);

};

