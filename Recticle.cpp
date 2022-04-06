#include "Recticle.h"

Recticle::Recticle()
{
}

Recticle::Recticle(int scrWidth, int scrHeight) : SObj( scrWidth, scrHeight)
{
	setSprite("data/reticle.png");
}

void Recticle::setX(int x)
{
	posX = x;
	if (posX < 0) std::cout << " Something is really wrongh with X recticle position " << std::endl;
}

void Recticle::setY(int y)
{
	posY = y;
	if (posY < 0) std::cout << " Something is really wrongh with Y recticle position " << std::endl;
}
