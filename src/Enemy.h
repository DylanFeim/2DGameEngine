#pragma once

class Enemy : public Character {
public:

	int targetPosX;
	int targetPosY;
	int movementTimer;
	int attackTimer;
	int range;
	int attackCooldown;

	int* playerPosX;
	int* playerPosY;

	bool movingTowardsTarget;
	bool hasAgro;

	float dist();
	void checkHit(int hitDmg);

	virtual void targetPlayer(int x, int y);
	virtual void die();
	virtual void draw();
	virtual void update();

};