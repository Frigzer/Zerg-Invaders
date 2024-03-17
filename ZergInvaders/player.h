#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Player
{
private:

	//Aktualna wartoœæ ¿ycia gracza
	int hp;

	//Maksymalna wartoœæ ¿ycia
	int hpMax;

	//Prêdkoœæ poruszania siê
	float movementSpeed;

	//Aktualny cooldown
	float attackCooldown;

	//Czas pomiêdzy którym mo¿na atakowaæ
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

	//Poruszanie siê
	void move(float x, float y);

	//Czy gracz mo¿e atakowaæ
	bool canAttack();

	//Aktualizuje czas ataku
	void updateAttack();

	//Zwraca wartoœæ hp
	int& getHp();

	//Zwraca maksymaln¹ wartoœæ hp
	int& getHpMax();

	//Zmniejsza wartoœæ hp
	void loseHp(int damage);

	//Aktualizowanie gracza
	void update();

	//Renderowanie gracza
	void render(sf::RenderTarget* target);
};

