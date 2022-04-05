

#include "Framework.h"



/* Test Framework realization */
class MyFramework : public Framework {

public:

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = 320;
		height = 200;
		fullscreen = false;
	}

	virtual bool Init() {

		//drawTestBackground();
		//Sprite* mySprite = nullptr;
		//mySprite = createSprite("data/big_asteroid.bmp");

		
		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {

		drawTestBackground();
		Sprite* mySprite = nullptr;
		mySprite = createSprite("data/big_asteroid.png");
		drawSprite(mySprite, 10, 10);
   
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {

	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {

	}

	virtual void onKeyPressed(FRKey k) {
	}

	virtual void onKeyReleased(FRKey k) {
	}
	
	virtual const char* GetTitle() override
	{
		return "asteroids";
	}
};

int main(int argc, char *argv[])
{
	

	MyFramework myFramework;
	//drawSprite(mySprite, 10, 10);
	myFramework.Init();
	//myFramework.Tick();
	return run(&myFramework);
}
