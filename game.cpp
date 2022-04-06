

#include "Framework.h"
#include <iostream>
#include "Aster.h"



/* Test Framework realization */
class MyFramework : public Framework {

public:


	
	int asterQuant =10;

	SObj sShip;

	Aster asterSmall;
	Aster asterBig;

	int scrWidth;
	int scrHeight;

	


	virtual void PreInit(int& width, int& height, bool& fullscreen) 
	{
		width = 800;
		height =600;
		fullscreen = false;
	}

	virtual bool Init() { //runs automatically  on create obj

		getScreenSize(scrWidth, scrHeight);
		std::cout << " scrWidth " << scrWidth << " scrHeight " << scrHeight << std::endl; 

		
		sShip = SObj(scrWidth, scrHeight);
		sShip.setSprite("data/spaceship.png");
		
		asterSmall = Aster(scrWidth, scrHeight);
		asterSmall.setSprite("data/small_asteroid.png");

		asterBig = Aster(scrWidth, scrHeight);
		asterBig.setSprite("data/big_asteroid.png");


		
		return true;
	}

	virtual void Close() {

	}

	void update() {
		
		asterSmall.addx( 3 );
		asterSmall.addy( 3 );

		asterBig.addx( 2 );
		asterBig.addy( 1 );


	}

	void draw() {

		drawTestBackground();

		drawSprite(sShip.getSprite(), sShip.x(), sShip.y());

		drawSprite(asterSmall.getSprite(), asterSmall.x(), asterSmall.y());
		
		drawSprite(asterBig.getSprite(), asterBig.x(), asterBig.y());

		
	
	}

	virtual bool Tick() {

		
		update();
		draw();
		
		
		

		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {
		//std::cout << " Mouse " << " _ " << " moved" << std::endl;

	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {
		if (button == FRMouseButton::LEFT && isReleased == true) {
			std::cout << " LEFT " << " Mouse Button " << " is clicked" << std::endl;
			
		}		
		if (button == FRMouseButton::MIDDLE && isReleased == true) {
			std::cout << " MIDDLE " << " Mouse Button " << " is clicked" << std::endl;
		}		
		if (button == FRMouseButton::RIGHT && isReleased == true) {
			std::cout << " RIGHT " << " Mouse Button " << " is clicked" << std::endl;
		}


	}

	virtual void onKeyPressed(FRKey k) {
		if (k == FRKey::UP) { 
			std::cout << " Key " << " UP " << " is pressed" << std::endl; 
			//posY -= 25; 
			//std::cout << " sShip position X: " << posX << " Y: " << posY << std::endl;
		}
		if (k == FRKey::DOWN) { 
			std::cout << " Key " << " DOWN " << " is pressed" << std::endl; 
			//posY += 25; 
			//std::cout << " sShip position X: " << posX << " Y: " << posY << std::endl;
		}
		if (k == FRKey::LEFT) {
			std::cout << " Key " << " LEFT " << " is pressed" << std::endl;
			//posX -= 25; 
		}
		if (k == FRKey::RIGHT) { 
			std::cout << " Key " << " RIGHT " << " is pressed" << std::endl; 
			//posX += 25; 
		}
	


		
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
