

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

	int currentTime = 0;
	int previousTime = 0;
	int elapsed = 0;
	int lag=0;
	int milliscePerUpdate = 17;
	int resetTime = 0;

	
	static const int asterQuant = 30;
	static const int bulletQuant = 50;

	SObj background;

	Recticle recticle;

	SpaceShip sShip;

	std::vector <Bullet> bullets;
	
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

		for (int i = 0; i < bulletQuant; i++) {
			bullets.push_back(Bullet(scrWidth, scrHeight));
		}
		
		
		
		for (int i = 0; i < asterQuant; i++) {
			bigAsteroids.push_back(Aster(scrWidth, scrHeight));
		}

		for (int i = 0; i < asterQuant; i++) {
			bigAsteroids.at(i).setSpeed(2);
			bigAsteroids[i].print();
		}


		
		return true;
	}

	virtual void Close() {

	}

	void update() {
		
		for (int i = 0; i < bulletQuant;i++) {
		
			bullets[i].move();
		}
	


		for (int i = 0; i < asterQuant; i++) {
			bigAsteroids[i].move();

			sShip.isIntersect( bigAsteroids[i].getCenterX(), bigAsteroids[i].getCenterY(), bigAsteroids[i].getRadius() );

			for (int y = 0; y < bulletQuant; y++) {
				if (bullets[y].exist() && bigAsteroids[i].exist() && bullets[y].isIntersect(bigAsteroids[i].getCenterX(), bigAsteroids[i].getCenterY(), bigAsteroids[i].getRadius())) {
					bigAsteroids[i].destroy();
					bullets[y].destroy();
				}
			
			}
			


		}




	}

	void draw() {


		tileBackground();

		drawSprite(background.getSprite(),0,0);

		drawSprite(sShip.getSprite(), sShip.x(), sShip.y());

		for (int i = 0; i < asterQuant; i++) {
			if (bigAsteroids[i].exist()) {
				drawSprite(bigAsteroids[i].getSprite(), bigAsteroids[i].x(), bigAsteroids[i].y());
			}
		}

		for (int i = 0; i < bulletQuant; i++) {
			if (bullets[i].exist()) {
				drawSprite(bullets[i].getSprite(), bullets[i].x(), bullets[i].y());
			}
		}

		drawSprite(recticle.getSprite(), recticle.x(), recticle.y());
	}

	virtual bool Tick() {

		previousTime = currentTime;
		currentTime = getTickCount();
		elapsed = currentTime - previousTime; // how much in mseconds takes 1 cycle
		lag += elapsed; // store how many cycles*mseconds i want skip
		resetTime += elapsed;

		while (lag >= milliscePerUpdate) //reverse time 
		{

			update();
			lag -= milliscePerUpdate;
		}

		draw();
		
		respawnAsteroids();



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
			for (int i = 0; i < bulletQuant; i++) {
				if (bullets[i].exist() == false) {
					bullets[i].shoot(sShip.x(), sShip.y(), recticle.x() , recticle.y() );
					break;
				}
				//TODO respawn bullets
			
			}

			
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

	void tileBackground() {
		int tilesW;
		int tilesH;

		tilesW = scrWidth / background.w();
		tilesH = scrHeight / background.h();
		
		for (int i = 0; i < tilesW +1; i++) { //+1 to cower half tile on screen 
			for (int j = 0; j < tilesH +1; j++) {
				drawSprite(background.getSprite(), i * background.w(), j * background.h());
			
			}
		}
	
	}

	void respawnAsteroids() {

		if (resetTime > 5000) {

			for (int i = 0; i < asterQuant; i++) {
				if (!bigAsteroids[i].exist()) {
					
					
					
					bigAsteroids[i].spawn(sShip.x(),sShip.y());

				}
			}
			resetTime = 0;
		}
	}


};

int main(int argc, char* argv[])
{

	MyFramework myFramework;

	return run(&myFramework);
}
