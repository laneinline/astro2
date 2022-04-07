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
