#include "ofApp.h"

Physics::Physics()
{
}

Physics::~Physics()
{
}

void Physics::move(Character* chr, bool w, bool a, bool s, bool d)
{
	cout << chr->getX() << ", " << chr->getY() << endl;

	if (chr->alive) {
		if (w == true || a == true || s == true || d == true) {

			if (chr->getAttacking() == false) {
				chr->setState(2);
			}
			chr->setMoving(1);

			if (w == true && s == false && a == d && a == false) {
				if((chr->getX() > 530 && chr->getY() > 400) || chr->getY() > 670)	
				chr->move(0);	
			}
			else if (w == true && d == true && s == false && a == false)
				chr->move(1);
			else if (w == s && w == false && a == false && d == true)
				chr->move(2);
			else if (s == true && w == false && d == true && a == false)
				chr->move(3);
			else if (s == true && w == false && a == d && a == false)
				chr->move(4);
			else if (s == true && a == true && w == false && d == false)
				chr->move(5);
			else if (a == true && d == false && w == s && w == false) {
				if ((chr->getX() > 530 && chr->getY() > 480)|| chr->getY() > 670)
					chr->move(6);
			}
			else if (a == true && w == true && s == false && d == false)
				chr->move(7);
		}
		else {

			if (chr->getMoving() == 1) {
				chr->setState(0);
				chr->setMoving(0);
			}
		}
	}
}

void Physics::dash(Character* chr)
{

}
