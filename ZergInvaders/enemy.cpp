#include "enemy.h"

//Metody prywatne

void Enemy::initEnemy(int type, int stage)
{
	deathTimer = 0.f;

	deathDuration = 0.4f;

	if(type >= 80 && type<100)
	{
		movementSpeed = 1.f;
		attackCooldownMax = 10.f;
		attackCooldown = 0.f;
		points = 20*stage;
		hpMax = stage;
		hp = hpMax;

		if (!texture.loadFromFile("Textures/zerg_guardian_1.png"))
		{
			std::cout << "!ERROR::ENEMY::INITENEMY::Nie mozna zaladowac textury." << std::endl;
		}

		enemy.setTexture(texture);

		enemyType = 1;
	}
	else if(type >= 50 && type < 80)
	{
		movementSpeed = 1.f;
		attackCooldownMax = 10.f;
		attackCooldown = attackCooldownMax;
		hpMax = stage;
		hp = hpMax;
		points = 40*stage;

		if (!texture.loadFromFile("Textures/zerg_broodlord_1.png"))
		{
			std::cout << "!ERROR::ENEMY::INITENEMY::Nie mozna zaladowac textury." << std::endl;
		}

		enemy.setTexture(texture);

		enemyType = 2;
	}
	else if(type==400)
	{
		movementSpeed = 2.f * stage;
		points = 100;

		if (!texture.loadFromFile("Textures/zerg_queen_l.png"))
		{
			std::cout << "!ERROR::ENEMY::INITENEMY::Nie mozna zaladowac textury." << std::endl;
		}

		enemy.setTexture(texture);

		enemyType = 3;
	}
	else if (type==401)
	{
		movementSpeed = 2.f*stage;
		points = 100;

		if (!texture.loadFromFile("Textures/zerg_queen_r.png"))
		{
			std::cout << "!ERROR::ENEMY::INITENEMY::Nie mozna zaladowac textury." << std::endl;
		}

		enemy.setTexture(texture);

		enemyType = 3;
	}
	else
	{
		movementSpeed = 1.f;
		points = 10;
		hpMax = 1;
		hp = hpMax;
		if (!texture.loadFromFile("Textures/zerg_overlord_1.png"))
		{
			std::cout << "!ERROR::ENEMY::INITENEMY::Nie mozna zaladowac textury." << std::endl;
		}

		enemy.setTexture(texture);

		enemyType = 3;
	}
	enemy.setScale(0.125f, 0.125f);
}

Enemy::Enemy()
{

}

//Konstruktor
Enemy::Enemy(int stage, int type, float x, float y)
{
	initEnemy(type, stage);
	enemy.setPosition(x, y);
}

Enemy::~Enemy()
{
}

//Metody

sf::FloatRect Enemy::getEnemyBounds()
{
	return enemy.getGlobalBounds();
}

sf::Vector2f Enemy::getEnemyPosition()
{
	return enemy.getPosition();
}

int Enemy::getEnemyType()
{
	return enemyType;
}

int& Enemy::getHp()
{
	return hp;
}

int& Enemy::getHpMax()
{
	return hpMax;
}

void Enemy::setHp(int value)
{
	hpMax = value;
}

void Enemy::loseHp(int damage)
{
	hp -= damage;
	if (hp <= 0)
	{
		hp = 0;
		isDead = true;
	}	
}

void Enemy::setEnemyTexture(sf::Texture texture)
{
	enemy.setTexture(texture);
}

void Enemy::setEnemyPosition(float x, float y)
{
	enemy.setPosition(x, y);
}

void Enemy::move(float dirX, float dirY)
{
	enemy.move(movementSpeed * dirX, movementSpeed * dirY);
}

bool Enemy::canAttack()
{
	if (attackCooldown >= attackCooldownMax)
	{
		attackCooldown = 0.f;
		return true;
	}
	return false;
}

bool Enemy::isAlive()
{
	return !isDead;
}

void Enemy::updateAttack()
{
	if (attackCooldown < attackCooldownMax)
		attackCooldown += 0.5f;
}

void Enemy::updateDeathAnimation()
{
	if (isDead)
	{
		deathTimer += 0.5f;
		if (deathTimer >= deathDuration)
		{
			isDead = false;
			deathTimer = 0;
		}
	}
}

int& Enemy::getPoints()
{
	return points;
}

void Enemy::update()
{
	updateAttack();
	updateDeathAnimation();
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(enemy);
}
