#include "ofApp.h"

void Enemy::targetPlayer(int x, int y)
{
	
}

void Enemy::die()
{
}

void Enemy::draw()
{
}

void Enemy::update()
{
}

float Enemy::dist()
{
	return (sqrt(pow((*playerPosX*1.0f - posX * 1.0f), 2) + pow((*playerPosY * 1.0f - posY * 1.0f), 2)));
}

void Enemy::checkHit(int hitDmg)
{
	if (dist() < 100)
		hit(hitDmg);
}
