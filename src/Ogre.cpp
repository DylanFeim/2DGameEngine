#include "ofApp.h"

Ogre::Ogre(int* pPosX, int* pPosY, Player* playerObj)
{
	posX = ofRandom(0, WIDTH);
	posY = ofRandom(0, HEIGHT);

	player = playerObj;

	playerPosX = pPosX;
	playerPosY = pPosY;

	targetPosX = posX;
	targetPosY = posY;

	hitTimer    = 0;
	alive		= 1;
	strength    = 1;
	deathValue  = 2;
	hp			= 0;
	orientation = 0;
	curFrame	= 0;
	state		= 0;
	timer		= 0;
	speed		= 1;
	maxFrame	= 0;
	moving		= 0;
	attacking	= 0;
	lastState   = 0;
	attackTimer = 0;
	hasAgro		= 0;
	range		= 100;
	movementTimer = 0;
	attackCooldown = 0;
	movingTowardsTarget = 0;


	for (int i = 0; i < OgreIdle; i++)
	{
		idleAnimation[i] = new ofImage();
	}

	for (int i = 0; i < OgreAttack; i++)
	{
		attackAnimation[i] = new ofImage();
	}

	for (int i = 0; i < OgreWalk; i++)
	{
		moveAnimation[i] = new ofImage();
	}

	for (int i = 0; i < OgreDeath; i++)
	{
		deathAnimation[i] = new ofImage();
	}


	idleAnimation[0]->load("OI1.png");
	idleAnimation[1]->load("OI2.png");
	idleAnimation[2]->load("OI3.png");
	idleAnimation[3]->load("OI4.png");
	idleAnimation[4]->load("OI5.png");
	idleAnimation[5]->load("OI6.png");

	attackAnimation[0]->load("OA1.png");
	attackAnimation[1]->load("OA2.png");
	attackAnimation[2]->load("OA3.png");
	attackAnimation[3]->load("OA4.png");
	attackAnimation[4]->load("OA5.png");
	attackAnimation[5]->load("OA6.png");
	attackAnimation[6]->load("OA7.png");
	attackAnimation[7]->load("OA8.png");
	attackAnimation[8]->load("OA9.png");
	attackAnimation[9]->load("OA10.png");
	attackAnimation[10]->load("OA11.png");

	moveAnimation[0]->load("OW1.png");
	moveAnimation[1]->load("OW2.png");
	moveAnimation[2]->load("OW3.png");
	moveAnimation[3]->load("OW4.png");
	moveAnimation[4]->load("OW5.png");
	moveAnimation[5]->load("OW6.png");
	moveAnimation[6]->load("OW7.png");
	moveAnimation[7]->load("OW8.png");
	moveAnimation[8]->load("OW9.png");
	moveAnimation[9]->load("OW10.png");
	moveAnimation[10]->load("OW11.png");

	deathAnimation[0]->load("OD1.png");
	deathAnimation[1]->load("OD2.png");
	deathAnimation[2]->load("OD3.png");
	deathAnimation[3]->load("OD4.png");
	deathAnimation[4]->load("OD5.png");
	deathAnimation[5]->load("OD6.png");
	deathAnimation[6]->load("OD7.png");
	deathAnimation[7]->load("OD8.png");
	deathAnimation[8]->load("OD9.png");
	deathAnimation[9]->load("OD10.png");
	deathAnimation[10]->load("OD11.png");
	deathAnimation[11]->load("OD12.png");
	deathAnimation[12]->load("OD13.png");
	deathAnimation[13]->load("OD14.png");
	deathAnimation[14]->load("OD15.png");
	deathAnimation[15]->load("OD16.png");
	deathAnimation[16]->load("OD17.png");
	deathAnimation[17]->load("OD18.png");
	deathAnimation[18]->load("OD19.png");
}

Ogre::Ogre(ofImage* attackArr, ofImage* walkArr, ofImage* dieArr, ofImage* idleArr, int* pPosX, int* pPosY, Player* playerObj)
{

	posX = ofRandom(0, WIDTH);
	posY = ofRandom(0, HEIGHT);

	playerPosX = pPosX;
	playerPosY = pPosY;

	targetPosX = posX;
	targetPosY = posY;

	hitTimer    = 0;
	alive		= 1;
	strength	= 1;
	deathValue  = 2;
	hp			= 0;
	orientation = 0;
	curFrame	= 0;
	state		= 0;
	timer		= 0;
	speed		= 4;
	maxFrame	= 0;
	moving		= 0;
	attacking	= 0;
	lastState   = 0;
	attackTimer = 0;
	targetPosX  = 0;
	targetPosY  = 0;
	hasAgro     = 0;
	range		= 100;
	movementTimer = 0;
	attackCooldown = 0;
	movingTowardsTarget = 0;



	
	for (int i = 0; i < OgreIdle; i++)
	{
		idleAnimation[i] = new ofImage();
		idleAnimation[i] = &idleArr[i];
	}

	for (int i = 0; i < OgreAttack; i++)
	{
		attackAnimation[i] = new ofImage();
		attackAnimation[i] = &attackArr[i];
	}

	for (int i = 0; i < OgreWalk; i++)
	{
		moveAnimation[i] = new ofImage();
		moveAnimation[i] = &walkArr[i];
	}

	for (int i = 0; i < OgreDeath; i++)
	{
		deathAnimation[i] = new ofImage();
		deathAnimation[i] = &dieArr[i];
	}

}

Ogre::~Ogre()
{

}

void Ogre::attack()
{
	attacking = 1;
	if (dist() < range / 2)
		player->hit(strength);
}

void Ogre::die()
{
	alive = 0;
	player->addMoney(deathValue);
}

void Ogre::draw()
{
	if (lastState != state) {
		curFrame = 0;
		lastState = state;
	}
	if (!alive)
		state = 3;

	switch (state) {
	case 0:
		idleAnimation[curFrame]->draw(posX, posY);
		maxFrame = OgreIdle;
		nextFrame(OgreIdleTime);
		break;
	case 1:
		attackAnimation[curFrame]->draw(posX, posY);
		maxFrame = OgreAttack;
		nextFrame(OgreAttackTime);
		break;
	case 2:
		moveAnimation[curFrame]->draw(posX, posY);
		maxFrame = OgreWalk;
		nextFrame(OgreWalkTime);
		break;
	case 3:
		deathAnimation[curFrame]->draw(posX, posY);
		maxFrame = OgreDeath;
		if (curFrame < OgreDeath-1)
		nextFrame(OgreDeathTime);
		break;

	}
}

void Ogre::move()
{
	if (posX < targetPosX - speed) {
		posX += speed;
		moving = 0;
	}
	else if (posX > targetPosX + speed) {
		posX -= speed;
		moving = 0;
	}

	if (posY < targetPosY - speed) {
		posY += speed;
		moving = 0;
	}
	else if (posY > targetPosY + speed) {
		posY -= speed;
		moving = 0;
	}

	if (posX < targetPosX - speed || posX > targetPosX + speed || posY < targetPosY - speed || posY > targetPosY + speed) {
		moving = 1;
	}

	if (hasAgro) {
		targetPosX = *playerPosX;
		targetPosY = *playerPosY;
	}

	if (posX > targetPosX - (speed * 2) && posX < targetPosX + (speed * 2) && posY > targetPosY - (speed * 2) && posY < targetPosY + (speed * 2) && hasAgro == false && movementTimer < 0) {
		targetPosX += ofRandom(-300, 300);
		targetPosY += ofRandom(-300, 300);

		movementTimer = OGRE_WAIT_MOVE;
	}
	else {
		movementTimer--;
	}

	if (orientation == 1 && targetPosX > posX) {
		orientation = 0;
		flip();
	}
	else if (orientation == 0 && targetPosX < posX) {
		orientation = 1;
		flip();
	}

}

void Ogre::update()
{
	if (alive) {
		if (dist() < AGRO_RANGE)
			hasAgro = true;
		if (dist() < range) {
			if (attackCooldown < 0)
				attackCooldown = OGRE_WAIT_ATTACK;
			attack();
		}
		else if(attackCooldown >0)
			attackCooldown--;
		updateState();
		move();
	}

	else
		state = 3;

}

void Ogre::updateState()
{
	if (attacking)
		state = 1;
	else {
		if (moving)
			state = 2;
		else
			state = 0;
	}
}

void Ogre::flip()
{
	for (int i = 0; i < OgreIdle; i++)
	{
		idleAnimation[i]->mirror(0, 1);
	}

	for (int i = 0; i < OgreAttack; i++)
	{
		attackAnimation[i]->mirror(0, 1);
	}

	for (int i = 0; i < OgreWalk; i++)
	{
		moveAnimation[i]->mirror(0, 1);
	}

	for (int i = 0; i < OgreDeath; i++)
	{
		deathAnimation[i]->mirror(0, 1);
	}

}
