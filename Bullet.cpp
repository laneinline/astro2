#include "Bullet.h"
#include <cmath>

Bullet::Bullet()
{
}

Bullet::Bullet(int scrWidth, int scrHeight) : SObj(scrWidth, scrHeight)
{
	setSprite("data/bullet.png");
	speed = 5;
	angle = 0;
	posX = scrWidth / 2;
	posY = scrHeight / 2;
	isExists = false;
}

void Bullet::shoot(int x, int y, int mouseX, int mouseY)
{
	posX = x;
	posY = y;
	isExists = true;
	//std::cout << " mouseX-x " << mouseX - x << " mouseY - y " <<  mouseY - y << std::endl;
	angle = -1*((atan2(mouseX-x,mouseY-y) *180/3.14159) -90); // 응응응응응응응응응응응응응응응응응응응응응� 
	//std::cout << "atan2(mouseX-x,mouseY-y) " << atan2(mouseX - x, mouseY - y) << " angle " << angle << std::endl;
	
}

void Bullet::destroy()
{
	isExists = false;
}

void Bullet::addAngle(int ang)
{
	angle = (angle + ang) % 360;
}
