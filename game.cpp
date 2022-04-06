

#include "Framework.h"
#include <iostream>
#include "Aster.h"



/* Test Framework realization */
class MyFramework : public Framework {

public:


	
	static const int asterQuant =3;

	SObj sShip;


	Aster asterList[asterQuant];

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
		sShip.print();
		

		for (int i = 0; i < asterQuant; i++) {
			asterList[i] = Aster(scrWidth,scrHeight);
			asterList[i].setSprite("data/big_asteroid.png");
			asterList[i].setSpeed(2);
			asterList[i].print();
		}


		
		return true;
	}

	virtual void Close() {

	}

	void update() {
		
		//asterSmall.move();

		//asterBig.move();

		for (int i = 0; i < asterQuant; i++) {
			asterList[i].move();

			sShip.isIntersect( asterList[i].getCenterX(), asterList[i].getCenterY(), asterList[i].getRadius() );
		}




	}

	void draw() {

		drawTestBackground();

		drawSprite(sShip.getSprite(), sShip.x(), sShip.y());

		//drawSprite(asterSmall.getSprite(), asterSmall.x(), asterSmall.y());
		
		//drawSprite(asterBig.getSprite(), asterBig.x(), asterBig.y());

		for (int i = 0; i < asterQuant; i++) {
			drawSprite(asterList[i].getSprite(), asterList[i].x(), asterList[i].y());

		}
		
	
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
			sShip.addy(-25); 


		}
		if (k == FRKey::DOWN) { 
			std::cout << " Key " << " DOWN " << " is pressed" << std::endl; 
			sShip.addy(25);

			
		}
		if (k == FRKey::LEFT) {
			std::cout << " Key " << " LEFT " << " is pressed" << std::endl;
			sShip.addx(-25);
		}
		if (k == FRKey::RIGHT) { 
			std::cout << " Key " << " RIGHT " << " is pressed" << std::endl; 
			sShip.addx(+25);
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

	return run(&myFramework);
}
