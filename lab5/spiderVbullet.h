#include "pixMap.h"
#include <iostream>
#include <chrono>
#include <thread>

const int screenWidth = 640;
const int screenHeight = 480;

class Point2
{

private:
	float x, y;

public:
	Point2() { x = y = 0.0f; }
	Point2(float xx, float yy)
	{
		this->x = xx;
		this->y = yy;
	}
	void set(float xx, float yy)
	{
		this->x = xx;
		this->y = yy;
	}
	float getX() { return this->x; }
	float getY() { return this->y; }

	void draw(void)
	{
		glPointSize(2.0);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
		glEnable(GL_POINT_SMOOTH);

		glBegin(GL_POINTS);
		glVertex2f((GLfloat)this->x, (GLfloat)this->y);
		glEnd();

		glDisable(GL_POINT_SMOOTH);
	}
};

class Spider
{
	// private:
public:
	RGBApixmap pix[4]; // make six empty pixmaps, one for each side of cube
	enum State
	{
		ALIVE,
		DEAD
	} state;
	// enum ModeType { STAY, RUN, BACK, JUMP, GROUNDED, SIT, DEAD } mode;

	// bool isDead;
	float pos_X, pos_Y;

	bool isMoving;
	float Vx;
	// sam
	Spider(Point2 pos)
	{
		pix[0].readBMPFile("mak3.bmp", 1);
		pix[1].readBMPFile("spider.bmp", 1);
		pix[2].readBMPFile("spider1.bmp", 1);
		pix[3].readBMPFile("splash.bmp", 1);

		// for(int i=0;i<6;i++)
		// 	pix[i].setChromaKey(192, 192, 192);

		this->pos_X = pos.getX();
		this->pos_Y = pos.getY();
		this->isMoving = false;
		this->Vx = 10;
	}

	void changePosition(float dx, float dy)
	{
		if (this->pos_X > 600)
			this->pos_X = 0.0;
		if (this->pos_X < 0)
			this->pos_X = 599;
		this->pos_X += dx;
		this->pos_Y += dy;
	}

	// void render();
	// void changeMode(ModeType m);
	// void run();
	// void back();
	// void jump();
	// void die();
	// void grounded();
};

Spider spider(Point2(0, 0));
