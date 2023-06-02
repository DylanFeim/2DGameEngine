#pragma once

class Player : public Character {
public:

	Player();
	~Player();

	ofImage* idleAnimation[2];
	ofImage* attackAnimation[8];
	ofImage* moveAnimation[4];
	ofImage* deathAnimation[8];

	int numSouls;

	void attack();
	void die();
	void dash();
	void draw();
	void flip();
	void addMoney(int n);
	int getSouls();
	int getAttacking();

};