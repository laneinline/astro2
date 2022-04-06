#pragma once
#include "SObj.h"
class Bullet :  public SObj
{
public: 
	Bullet();
	Bullet(int scrWidth, int  scrHeight);
	void shoot(int x, int y, int mouseX, int mouseY);
	void destroy();
	void addAngle(int ang);
};

