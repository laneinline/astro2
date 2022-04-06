#pragma once
#include "Framework.h"
#include <iostream>
#include <string>

class SObj
{
public:
	SObj();
	SObj(int scrWidth, int scrHeight);

	Sprite* getSprite();
	void setSprite(std::string path);

	int x();
	int y();
	void addx(int pos );
	void addy(int pos );

	void print();

protected:

	bool isExists;

	Sprite* sprite;

	int posX = 10 ;
	int posY = 10 ;

	int scrW;
	int scrH;
};

