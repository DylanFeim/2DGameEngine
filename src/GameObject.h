#pragma once


class GameObject {
public:
	int posX;
	int posY;
	int speed;
	int orientation;

	int getX();
	int getY();

	void setX(int x);
	void setY(int y);
	void move(int direction);
	virtual void draw();
	virtual void flip();

};