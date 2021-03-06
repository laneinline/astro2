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

	bool exist();

	int x();
	int y();
	int w();
	int h();
	int s();
	
	void setSpeed(int spd);
	void move();
	void reverseAngle();
	void addx(int pos );
	void addy(int pos );

	int getCenterX();
	int getCenterY();
	int getRadius();

	bool isIntersect(int x,int y, int targetRadius);

	void print();

protected:

	bool isExists;

	Sprite* sprite;


	int speed = 0;
	int angle = 0;
	float movedistX =0; 
	float movedistY =0; 

	int posX = 10 ;
	int posY = 10 ;
	int width = 15;
	int height = 15;

	int centrX = 11;
	int centrY = 11;
	int radius = 11;

	int scrW = 0;
	int scrH = 0;
};

