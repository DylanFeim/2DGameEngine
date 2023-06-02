#include "ofApp.h"

Player::Player()
{
	hp = 3;
	posX = WIDTH/2;
	posY = HEIGHT/2;

	 strength   = 3;
	 alive		= 1;
	 numSouls	= 0;
	 speed		= 5;
	 curFrame	= 0;
	 timer		= 0;
	 maxFrame	= 0;
	 state		= 0;
	 moving		= 0;
	 attacking  = 0;
	 orientation =0;
	 hitTimer   = 0;

	 for (int i = 0; i < PlayerIdle; i++)
	 {
		 idleAnimation[i] = new ofImage();
	 }

	 for (int i = 0; i < PlayerAttack; i++)
	 {
		 attackAnimation[i] = new ofImage();
	 }

	 for (int i = 0; i < PlayerWalk; i++)
	 {
		 moveAnimation[i] = new ofImage();
	 }

	 for (int i = 0; i < PlayerDeath; i++)
	 {
		 deathAnimation[i] = new ofImage();
	 }
	

	idleAnimation[0]->load("CI1.png");
	idleAnimation[1]->load("CI2.png");

	attackAnimation[0]->load("CA1.png");
	attackAnimation[1]->load("CA2.png");
	attackAnimation[2]->load("CA3.png");
	attackAnimation[3]->load("CA4.png");
	attackAnimation[4]->load("CA5.png");
	attackAnimation[5]->load("CA6.png");
	attackAnimation[6]->load("CA7.png");
	attackAnimation[7]->load("CA8.png");

	moveAnimation[0]->load("CW1.png");
	moveAnimation[1]->load("CW2.png");
	moveAnimation[2]->load("CW3.png");
	moveAnimation[3]->load("CW4.png");

	deathAnimation[0]->load("CD1.png");
	deathAnimation[1]->load("CD2.png");
	deathAnimation[2]->load("CD3.png");
	deathAnimation[3]->load("CD4.png");
	deathAnimation[4]->load("CD5.png");
	deathAnimation[5]->load("CD6.png");
	deathAnimation[6]->load("CD7.png");
	deathAnimation[7]->load("CD8.png");
}

Player::~Player()
{
}

void Player::attack()
{
	state = 1;
	attacking = 1;
}


void Player::die()
{
	alive = 0;
}

void Player::dash()
{
}

void Player::draw() {

	if (hitTimer > 250) {
	
		ofSetColor(ofColor::red);
	}

	if (!alive)
		state = 3;

	switch (state) {
	case 0:
		idleAnimation[curFrame]->draw(posX, posY);
		maxFrame = PlayerIdle;
		nextFrame(PlayerIdleTime);
		break;
	case 1:
		attackAnimation[curFrame]->draw(posX, posY);
		maxFrame = PlayerAttack;
		nextFrame(PlayerAttackTime);
		break;
	case 2:
		moveAnimation[curFrame]->draw(posX, posY);
		maxFrame = PlayerWalk;
		nextFrame(PlayerWalkTime);
		break;
	case 3:
		deathAnimation[curFrame]->draw(posX, posY);
		maxFrame = PlayerDeath;
		if(curFrame < PlayerDeath-1)
		nextFrame(PlayerDeathTime);
		break;

	}

	if (hitTimer > 0)
		hitTimer--;

	if (hitTimer <= HIT_WAIT-30) {

		ofSetColor(ofColor::white);
	}
}

void Player::flip()
{
	for (int i = 0; i < PlayerIdle; i++)
	{
		idleAnimation[i]->mirror(0,1);
	}

	for (int i = 0; i < PlayerAttack; i++)
	{
		attackAnimation[i]->mirror(0, 1);
	}

	for (int i = 0; i < PlayerWalk; i++)
	{
		moveAnimation[i]->mirror(0, 1);
	}

	for (int i = 0; i < PlayerDeath; i++)
	{
		deathAnimation[i]->mirror(0, 1);
	}
}

void Player::addMoney(int n)
{
	numSouls += n;
}

int Player::getSouls()
{
	return numSouls;
}

int Player::getAttacking()
{
	return attacking;
}

