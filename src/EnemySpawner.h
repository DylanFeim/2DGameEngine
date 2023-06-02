#pragma once

class EnemySpawner : public GameObject{
public:

	EnemySpawner(Player* playerObj);

	ofImage* ogreIdleAnimation[16];
	ofImage* ogreAttackAnimation[16];
	ofImage* ogreMoveAnimation[16];
	ofImage* ogreDeathAnimation[20];

	vector<Ogre> ogreArr;

	Player* player;

	int* playerPosX;
	int* playerPosY;

	void spawnMonster(int id);
	void updateMonsters();
	void draw();
	void checkHit(int hitDmg);

};