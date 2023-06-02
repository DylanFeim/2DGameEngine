#include "ofApp.h"

Render::Render()
{

}
Render::~Render()
{

}

void Render::display(GameObject* obj)
{
	obj->draw();
}
