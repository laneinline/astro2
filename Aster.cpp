#include "Aster.h"



Aster::Aster()
{
	//std::cout << " Aster() constructor " << std::endl;
}

Aster::Aster(int scrWidth, int scrHeight) : SObj ( scrWidth, scrHeight)
{
	setSprite("data/big_asteroid.png");
	setSpeed(1);
	//std::cout << " Aster(int scrWidth, int scrHeight) constructor " << std::endl;
}

void Aster::destroy()
{
	isExists = false;
}

void Aster::create()
{

	isExists = true;
}

void Aster::spawn(int targetX, int targetY)
{//todo add better check
	if (posX <= targetX && posX + 150 > targetX) addx(- 150); // all asteroids that spawn near ship at the left -> moved left abit 
	
	if (posX >= targetX && posX - 150 < targetX) addx(150);

	if (posY<= targetY && posY + 150 > targetY) addy(-150);

	if (posY>= targetY && posY - 150 < targetY) addy(150);
	isExists = true;
}
