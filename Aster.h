#pragma once
#include "Framework.h"
#include "SObj.h"
class Aster :public SObj
{
public:
	Aster();
	Aster(int scrWidth,int scrHeight);
	
	void destroy();
	void create();
	void spawn(int targetX, int targetY );




};

