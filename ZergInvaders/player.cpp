#include "player.h"

//Metody prywatne

void Player::initPlayer()
{
	movementSpeed = 10.f;

	attackCooldownMax = 20.f;

	attackCooldown = attackCooldownMax;

	hpMax = 3;

	hp = hpMax;

	if (!texture.loadFromFile("Textures/terran_wraith_1.png"))
	{
		std::cout << "!ERROR::PLAYER::INITPLAYER::Nie mozna zaladowac textury." << std::endl;
	}
	player.setTexture(texture);

	player.setScale(0.1f, 0.1f);
}

//Konstruktor
Player::Player()
{
	initPlayer();

}

Player::~Player()
{
}

//Metody

sf::FloatRect Player::getPlayerBounds()
{
	return player.getGlobalBounds();
}

sf::Vector2f Player::getPlayerPosition()
{
	return player.getPosition();
}

void Player::setPlayerPosition(float x, float y)
{
	player.setPosition(x, y);
}

void Player::setHp(int value)
{
	hp = value;
}

void Player::move(float dirX, float dirY)
{
	player.move(movementSpeed * dirX, movementSpeed * dirY);
}

bool Player::canAttack()
{
	if (attackCooldown >= attackCooldownMax)
	{
		attackCooldown = 0.f;
		return true;
	}
	return false;
}

void Player::updateAttack()
{
	if (attackCooldown < attackCooldownMax)
		attackCooldown += 0.5f;
}

int& Player::getHp()
{
	return hp;
}

int& Player::getHpMax()
{
	return hpMax;
}

void Player::loseHp(int damage)
{
	hp -= damage;
	if (hp <= 0)
		hp = 0;
}

void Player::update()
{
	updateAttack();
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(player);
}
