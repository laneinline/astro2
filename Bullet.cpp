#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(int scrWidth, int scrHeight) : SObj(scrWidth, scrHeight)
{
	setSprite("data/bullet.png");
	speed = 5;
}
