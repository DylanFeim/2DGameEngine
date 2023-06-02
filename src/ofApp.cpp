#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetRectMode(OF_RECTMODE_CENTER);
	ofDisableSmoothing();
	ofSetFrameRate(240);
	ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL);

	w = false;
	a = false;
	s = false;
	d = false;
	shift = false;

	map = new Map();
	player = new Player();
	render = new Render();
	physics = new Physics();
	enemySpawner = new EnemySpawner(player);





}

//--------------------------------------------------------------
void ofApp::update(){

	physics->move(player, w, a, s, d);
	enemySpawner->updateMonsters();
	if (player->getAttacking())
		enemySpawner->checkHit(player->getAttacking());
	if (ofRandom(0, 1) < 0.05);
	

}

//--------------------------------------------------------------
void ofApp::draw() {

	render->display(map);
	render->display(enemySpawner);
	render->display(player);
	ofPushMatrix();
	ofScale(3, 3);
	ofDrawBitmapString("Souls: " + ofToString(player->getSouls()), 25, 350);

	ofPopMatrix();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){


	//cout << key << endl;

	switch (key) {
	case 119:		//w
		w = true;
		break;
	case 97:		//a
		a = true;
		break;
	case 115:		//s
		s = true;
		break;
	case 100:		//d
		d = true;
		break;
	case 3680:		//shift
		shift = true;
		break;
	case 32:
		enemySpawner->spawnMonster(0);
		break;
	}





}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	cout << key << endl;

	switch (key) {
	case 119:		//w
		w = false;
		break;
	case 97:		//a
		a = false;
		break;
	case 115:		//s
		s = false;
		break;
	case 100:		//d
		d = false;
		break;
	case 3680:		//shift
		shift = false;
		break;
	}


}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (button == 0) {
		player->attack();
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

