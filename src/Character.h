#pragma once

class Character : public GameObject {
public:
	int hp;
	int curFrame;
	int maxFrame;
	int state;
	int timer;
	int alive;
	bool moving;
	bool attacking;
	int strength;
	int hitTimer;

	ofImage* idleAnimation[16];
	ofImage* attackAnimation[16];
	ofImage* moveAnimation[16];
	ofImage* deathAnimation[20];

	int getOrientation();
	int getFrame();

	void nextFrame(int speed);
	void hit(int x);
	void setState(int newState);
	void setMoving(bool n);
	bool getMoving();
	void setAttacking(bool n);
	bool getAttacking();


	virtual void die();
	virtual void attack();

};
