#include "ofApp.h"


int Character::getOrientation()
{
	return orientation;
}


void Character::nextFrame(int speed)
{

	if (timer > speed) {
		timer = 0;

		if (curFrame > maxFrame - 2) {
			curFrame = 0;
			state = 0;
			attacking = 0;
		}
		else
			curFrame++;
	}
	else
		timer++;

}

int Character::getFrame()
{
	return curFrame;
}

void Character::hit(int x)
{
	if (hitTimer <= 0) {
		hitTimer = HIT_WAIT;
		cout << "hit" << endl;
		hp -= x;
		if (hp <= 0)
			die();
	}

}

void Character::setState(int newState)
{
	state = newState;
}

void Character::setMoving(bool n)
{
	moving = n;
}

bool Character::getMoving()
{
	return moving;
}

void Character::setAttacking(bool n)
{
	attacking = n;
}

bool Character::getAttacking()
{
	return attacking;
}

void Character::die()
{
}

void Character::attack()
{
}

