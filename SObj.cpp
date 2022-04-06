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

    getSpriteSize(getSprite(), width, height);

    radius = width / 2;

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

bool SObj::exist()
{
    return isExists;
}

int SObj::x()
{
    return posX;
}

int SObj::y()
{
    return posY;
}

int SObj::s()
{
    return speed;
}

void SObj::setSpeed(int spd)
{
    speed = spd;

}

void SObj::move()
{
    //angle += 10;
    addx((int)(speed * cos(angle * 3.14159 / 180 )));
    addy((int)(speed * sin(angle * 3.14159 / 180)));
}

void SObj::addx(int pos)
{
    posX += pos;
    if (posX < 0) { posX = scrW-radius; }
    if (posX > scrW) { posX = 0; }
}

void SObj::addy(int pos)
{
    posY += pos;
    if (posY < 0) { posY = scrH -radius; }
    if (posY > scrH) { posY = 0; }
}

int SObj::getCenterX()
{
    getSpriteSize(getSprite(),width,height );
    centrX = posX + width/2;

    if (centrX < 0) std::cout << " Something is really wrongh with sprite width. " << std::endl;

    return centrX;
}

int SObj::getCenterY()
{
    getSpriteSize(getSprite(), width, height);
    centrY = posY + height/2;

    if (centrY < 0) std::cout << " Something is really wrongh with sprite height. " << std::endl;

    return centrY;
}

int SObj::getRadius()
{
    return radius;
}

bool SObj::isIntersect(int x, int y, int targetRadius)
{
    bool intersect ;

    if (//simple   a^2 + b^2 =c^2 detection
        ((getCenterX() - x) * (getCenterX() - x)
        + (getCenterY() - y) * (getCenterY() - y)) 
        < (radius * radius + targetRadius * targetRadius)
        ) {

        intersect = true;
        //std::cout << " Collizionnn!!!";
    }
    else {
        intersect = false;
    }

    return intersect;
}

void SObj::print()
{
    std::cout << "SObj " << " posX: " << posX << " posY: " << posY
        << " scrW: " << scrW << " scrH: " << scrH
        << " Speed: " << speed << " Angle: " << angle
        << " center X: " << getCenterX() << " center Y : " << getCenterY()
        << " radius: " << getRadius()
        << std::endl;
}


