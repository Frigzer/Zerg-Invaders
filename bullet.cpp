#include "bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
	bullet.setTexture(*texture);

	bullet.setPosition(pos_x, pos_y);
	directions.x = dir_x;
	directions.y = dir_y;
	movementSpeed = movement_speed;
	bullet.setScale(0.5f, 0.5f);
}

Bullet::~Bullet()
{
}

const sf::FloatRect Bullet::getBounds() const
{
	return bullet.getGlobalBounds();
}

void Bullet::update()
{
	bullet.move(movementSpeed * directions);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(bullet);
}
