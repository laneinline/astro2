#pragma once
#include "SObj.h"
class Recticle :   public SObj
{
public:
    Recticle();
    Recticle(int scrWidth, int scrHeight);
    void setX(int x);
    void setY(int y);
};

