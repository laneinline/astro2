

#include "Framework.h"
#include <iostream>



/* Test Framework realization */
class MyFramework : public Framework {

public:

	Sprite* sShip = nullptr;
	int posX = 100;
	int	posY = 100;

	int scrWidth;
	int scrHeight;


	virtual void PreInit(int& width, int& height, bool& fullscreen) 
	{
		width = 800;
		height =600;
		fullscreen = false;
	}

	virtual bool Init() { //runs automatically  on create obj

		drawTestBackground();
		//Sprite* mySprite = nullptr;
		//mySprite = createSprite("data/big_asteroid.bmp");


		getScreenSize(scrWidth, scrHeight);
		std::cout << " scrWidth " << scrWidth << " scrHeight " << scrHeight << std::endl; 

		posX = scrWidth / 2;
		posY = scrHeight / 2;

		sShip = createSprite("data/spaceship.png");
		std::cout << " sShip position X: " << posX << " Y: " << posY << std::endl;

		
		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {

		drawTestBackground();

		drawSprite(sShip, posX, posY);
		
		//int w, h;
		//getScreenSize(w,h);
		//std::cout << " w: " << w << " h: " << h << std::endl;

		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {
		std::cout << " Mouse " << " _ " << " moved" << std::endl;

	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {
		std::cout << " Mouse " << " Button " << " is clicked" << std::endl;

	}

	virtual void onKeyPressed(FRKey k) {
		if (k == FRKey::UP) { 
			std::cout << " Key " << " UP " << " is pressed" << std::endl; 
			posY -= 25; 
			std::cout << " sShip position X: " << posX << " Y: " << posY << std::endl;
		}
		if (k == FRKey::DOWN) { 
			std::cout << " Key " << " DOWN " << " is pressed" << std::endl; 
			posY += 25; 
			std::cout << " sShip position X: " << posX << " Y: " << posY << std::endl;
		}
		if (k == FRKey::LEFT) { std::cout << " Key " << " LEFT " << " is pressed" << std::endl; posX -= 25; }
		if (k == FRKey::RIGHT) { std::cout << " Key " << " RIGHT " << " is pressed" << std::endl; posX += 25; }
	


		
	}

	virtual void onKeyReleased(FRKey k) {
		//std::cout << " Key " << " UP " << " is released" << std::endl;
	}
	
	virtual const char* GetTitle() override
	{
		return "asteroids";
	}


};

int main(int argc, char* argv[])
{


	MyFramework myFramework;
	//drawSprite(mySprite, 10, 10);
	//myFramework.Init();


	return run(&myFramework);
}
