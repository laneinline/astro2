

#include "Framework.h"
#include <iostream>
#include <vector>
#include "Aster.h"
#include "Bullet.h"
#include "Recticle.h"
#include "SpaceShip.h"




/* Test Framework realization */
class MyFramework : public Framework {

public:


	
	static const int asterQuant = 10;

	SObj background;

	Recticle recticle;

	SpaceShip sShip;

	Bullet bullet;
	
	std::vector <Aster> bigAsteroids;

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

		background = SObj(scrWidth,scrHeight);
		background.setSprite("data/background.png");

		recticle = Recticle(scrWidth,scrHeight);
		showCursor(false);
		
		sShip = SpaceShip(scrWidth, scrHeight);

		bullet = Bullet(scrWidth,scrHeight);
		
		for (int i = 0; i < asterQuant; i++) {
			bigAsteroids.push_back(Aster(scrWidth, scrHeight));
			
		}
		std::cout << "vector of asteroid size " << bigAsteroids.size() << std::endl;

		for (int i = 0; i < asterQuant; i++) {
			bigAsteroids.at(i).setSpeed(2);
			bigAsteroids[i].print();
		}


		
		return true;
	}

	virtual void Close() {

	}

	void update() {
		
	
		bullet.move();

		for (int i = 0; i < asterQuant; i++) {
			bigAsteroids[i].move();

			sShip.isIntersect( bigAsteroids[i].getCenterX(), bigAsteroids[i].getCenterY(), bigAsteroids[i].getRadius() );
			if (bullet.isIntersect(bigAsteroids[i].getCenterX(), bigAsteroids[i].getCenterY(), bigAsteroids[i].getRadius())) {
				bigAsteroids[i].destroy();
			}


		}




	}

	void draw() {

		drawTestBackground();

		drawSprite(background.getSprite(),0,0);//TODO tile background with sprites

		drawSprite(sShip.getSprite(), sShip.x(), sShip.y());

		for (int i = 0; i < asterQuant; i++) {
			if (bigAsteroids[i].exist()) {
				drawSprite(bigAsteroids[i].getSprite(), bigAsteroids[i].x(), bigAsteroids[i].y());
			}
			

		}

		drawSprite(bullet.getSprite(),bullet.x(),bullet.y());
		
		drawSprite(recticle.getSprite(), recticle.x(), recticle.y());
	}

	virtual bool Tick() {

		
		update();
		draw();

		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {
		//std::cout << " Mouse x: " << x << " y " << y << " moved" << std::endl;
		recticle.setX(x);
		recticle.setY(y);
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
