#include "SObj.h"

SObj::SObj()
{
    //std::cout << " SObj() constructor " << std::endl;
}

SObj::SObj(int scrWidth, int scrHeight)
{
    scrW = scrWidth;
    scrH = scrHeight;
    sprite = createSprite("data/err.png");
    //std::cout << " SObj(int scrWidth, int scrHeight) constructor " << std::endl;
}

Sprite* SObj::getSprite()
{
    return sprite;
}

void SObj::setSprite(std::string path)
{
    sprite = createSprite(path.c_str());
}

int SObj::x()
{
    return posX;
}

int SObj::y()
{
    return posY;
}

void SObj::addx(int pos)
{
    posX += pos;
    if (posX < 0) { posX = scrW; }
    if (posX > scrW) { posX = 0; }
}

void SObj::addy(int pos)
{
    posY += pos;
    if (posY < 0) { posX = scrH; }
    if (posY > scrH) { posY = 0; }
}

void SObj::print()
{
    std::cout << "SObj " << " posX: " << posX << " posY: " << posY << " scrW: " << scrW << " scrH: " << scrH << std::endl;
}


