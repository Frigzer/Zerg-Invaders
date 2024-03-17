#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class Bullet
{
private:

	//Pocisk
	sf::Sprite bullet;

	//Kierunek pocisku
	sf::Vector2f directions;

	//Prêdkoœæ pocisku
	float movementSpeed;

public:
	Bullet();

	//Konstruktor
	Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed);

	~Bullet();

	//Metody dostepu

	//Pobiera rozmiary pocisku
	const sf::FloatRect getBounds() const;

	//Aktualizacja pocisku
	void update();

	//Renderowanie pocisku
	void render(sf::RenderTarget* target);
};


