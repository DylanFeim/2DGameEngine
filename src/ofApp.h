#pragma once
#include "Math.h"
#include "ofMain.h"
#include "GlobalVal.h"
#include "GameObject.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Ogre.h"
#include "EnemySpawner.h"
#include "Game.h"
#include "Map.h"
#include "Render.h"
#include "Physics.h"

class ofApp : public ofBaseApp{

	public:

		bool w;
		bool a;
		bool s;
		bool d;
		bool shift;

		Map* map;
		Player* player;
		Render* render;
		Physics* physics;
		EnemySpawner* enemySpawner;




		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		
};
