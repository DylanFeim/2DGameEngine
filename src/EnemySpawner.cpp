#include "ofApp.h"

EnemySpawner::EnemySpawner(Player* playerObj)
{
	player = playerObj;

	playerPosX = &player->posX;
	playerPosY = &player->posY;


	for (int i = 0; i < OgreIdle; i++)
	{
		ogreIdleAnimation[i] = new ofImage();
	}

	for (int i = 0; i < OgreAttack; i++)
	{
		ogreAttackAnimation[i] = new ofImage();
	}

	for (int i = 0; i < OgreWalk; i++)
	{
		ogreMoveAnimation[i] = new ofImage();
	}

	for (int i = 0; i < OgreDeath; i++)
	{
		ogreDeathAnimation[i] = new ofImage();
	}


	ogreIdleAnimation[0]->load("OI1.png");
	ogreIdleAnimation[1]->load("OI2.png");
	ogreIdleAnimation[2]->load("OI3.png");
	ogreIdleAnimation[3]->load("OI4.png");
	ogreIdleAnimation[4]->load("OI5.png");
	ogreIdleAnimation[5]->load("OI6.png");

	ogreAttackAnimation[0]->load("OA1.png");
	ogreAttackAnimation[1]->load("OA2.png");
	ogreAttackAnimation[2]->load("OA3.png");
	ogreAttackAnimation[3]->load("OA4.png");
	ogreAttackAnimation[4]->load("OA5.png");
	ogreAttackAnimation[5]->load("OA6.png");
	ogreAttackAnimation[6]->load("OA7.png");
	ogreAttackAnimation[7]->load("OA8.png");
	ogreAttackAnimation[8]->load("OA9.png");
	ogreAttackAnimation[9]->load("OA10.png");
	ogreAttackAnimation[10]->load("OA11.png");

	ogreMoveAnimation[0]->load("OW1.png");
	ogreMoveAnimation[1]->load("OW2.png");
	ogreMoveAnimation[2]->load("OW3.png");
	ogreMoveAnimation[3]->load("OW4.png");
	ogreMoveAnimation[4]->load("OW5.png");
	ogreMoveAnimation[5]->load("OW6.png");
	ogreMoveAnimation[6]->load("OW7.png");
	ogreMoveAnimation[7]->load("OW8.png");
	ogreMoveAnimation[8]->load("OW9.png");
	ogreMoveAnimation[9]->load("OW10.png");
	ogreMoveAnimation[10]->load("OW11.png");

	ogreDeathAnimation[0]->load("OD1.png");
	ogreDeathAnimation[1]->load("OD2.png");
	ogreDeathAnimation[2]->load("OD3.png");
	ogreDeathAnimation[3]->load("OD4.png");
	ogreDeathAnimation[4]->load("OD5.png");
	ogreDeathAnimation[5]->load("OD6.png");
	ogreDeathAnimation[6]->load("OD7.png");
	ogreDeathAnimation[7]->load("OD8.png");
	ogreDeathAnimation[8]->load("OD9.png");
	ogreDeathAnimation[9]->load("OD10.png");
	ogreDeathAnimation[10]->load("OD11.png");
	ogreDeathAnimation[11]->load("OD12.png");
	ogreDeathAnimation[12]->load("OD13.png");
	ogreDeathAnimation[13]->load("OD14.png");
	ogreDeathAnimation[14]->load("OD15.png");
	ogreDeathAnimation[15]->load("OD16.png");
	ogreDeathAnimation[16]->load("OD17.png");
	ogreDeathAnimation[17]->load("OD18.png");
	ogreDeathAnimation[18]->load("OD19.png");



}

void EnemySpawner::spawnMonster(int id)
{
	switch (id) {

	case 0:
		ogreArr.push_back(Ogre(playerPosX, playerPosY, player));
		//ogreArr.push_back(Ogre(*ogreIdleAnimation, *ogreAttackAnimation, *ogreMoveAnimation, *ogreDeathAnimation, playerPosX, playerPosY, player));
		break;
	}
	
}

void EnemySpawner::updateMonsters()
{
	for (int i = 0; i < ogreArr.size(); i++) {
		ogreArr[i].update();

	}
}

void EnemySpawner::draw()
{
	for (int i = 0; i < ogreArr.size(); i++) {
		ogreArr[i].draw();
	}
}

void EnemySpawner::checkHit(int hitDmg)
{
	for (int i = 0; i < ogreArr.size(); i++) {
		ogreArr[i].checkHit(hitDmg);
	}
}
