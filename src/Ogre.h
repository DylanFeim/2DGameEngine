#pragma once

class Ogre : public Enemy {
public:

	Ogre(int* pPosX, int *pPosY, Player* playerObj);
	Ogre(ofImage* attackArr, ofImage* walkArr, ofImage* dieArr, ofImage* idleArr, int* pPosX, int* pPosY, Player* playerObj);
	~Ogre();

	ofImage* idleAnimation[16];
	ofImage* attackAnimation[16];
	ofImage* moveAnimation[16];
	ofImage* deathAnimation[20];

	Player* player;

	int deathValue;
	int lastState;

	void attack();
	void die();
	void draw();
	void move();
	void update();
	void updateState();
	void flip();
};