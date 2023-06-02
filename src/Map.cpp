#include "ofApp.h"

Map::Map()
{
	mapImg.load("MAP01.png");
}

void Map::draw()
{
	mapImg.draw(WIDTH/2, HEIGHT/2);
}
