#include "SpaceShip.h"

SpaceShip::SpaceShip()
{
}

SpaceShip::SpaceShip(int scrWidth, int scrHeight) : SObj( scrWidth,  scrHeight)
{
	setSprite("data/spaceship.png");
	posX = scrWidth / 2;
	posY = scrHeight / 2;
	setAngle(0);
}

void SpaceShip::setAngle(int ang)
{
	angle = ang ;

}
