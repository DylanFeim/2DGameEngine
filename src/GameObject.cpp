#include "ofApp.h"

int GameObject::getX()
{
	return posX;
}

int GameObject::getY()
{
	return posY;
}

void GameObject::setX(int x)
{
	posX = x;
}

void GameObject::setY(int y)
{
	posY = y;
}

void GameObject::move(int direction){

	switch (direction) {
	case 0:				//N
		posY -= speed;
		break;
	case 1:				//NE
		posX += sqrt(speed);
		posY -= sqrt(speed);
		if (orientation == 1) {
			orientation = 0;
			flip();
		}
		break;
	case 2:				//E
		posX += speed;
		if (orientation == 1) {
			orientation = 0;
			flip();
		}
		break;
	case 3:				//ES
		posX += sqrt(speed);
		posY += sqrt(speed);
		if (orientation == 1) {
			orientation = 0;
			flip();
		}
		break;
	case 4:				//S
		posY += speed;
		break;
	case 5:				//SW
		posX -= sqrt(speed);
		posY += sqrt(speed);
		if (orientation == 0) {
			orientation = 1;
			flip();
		}
		break;
	case 6:				//W
		posX -= speed;
		if (orientation == 0) {
			orientation = 1;
			flip();
		}
		break;
	case 7:				//WN
		posX -= sqrt(speed);
		posY -= sqrt(speed);
		if (orientation == 0) {
			orientation = 1;
			flip();
		}
		break;
	}
}

void GameObject::draw()
{

}

void GameObject::flip()
{
}
