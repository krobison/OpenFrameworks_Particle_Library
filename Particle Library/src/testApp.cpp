#include "testApp.h"
#include "pclSystem.h"

//##WATER##
pclSystem system1(0.2);
	pclType water		("circle_hollow",6,12,42,164);
	pclType darkWater	("circle",6,6,12,66);
	pclType brightWater	("circle",6,24,72,200);
	pclType smallWater	("circle",2,12,42,164);

	pclEmitter sprinkler("point",1920,300);

	pclField att1(10000,1500,620);
	pclField def1(-5000,1600,850);
	pclField def2(-10000,1300,900);
	pclField def3(-6000,400,900);

pclSystem background(0);
	pclType		bigDots		("circle",20,3,12,32);
	pclEmitter	backSpawner	("rect",0,0,1920,1080);


void testApp::setup(){
	//##WATER##
			sprinkler.setSpeeds		(-5,-3,0,0);
			backSpawner.setSpeeds	(0,0,0,0);

			water.setDecays			(1.2,0.001,0,0.6,0);
			darkWater.setDecays		(1.2,0.001,0,0.6,0);
			brightWater.setDecays	(1.2,0.001,0,0.6,0);
			smallWater.setDecays	(1.2,0.001,0,0.6,0);
			bigDots.setDecays		(6,0,0.1,0.1,0.1);
		
			system1.addEmitter	(sprinkler);

			system1.addField(att1);
			system1.addField(def1);
			system1.addField(def2);
			system1.addField(def3);

			background.addEmitter(backSpawner);
//##ALL##
			ofSetFrameRate(65);
			ofBackground(0,0,0);
}

void testApp::update(){
	system1.burst(sprinkler,water,3);
	system1.burst(sprinkler,smallWater,2);
	int random = rand()%10;
	if (random == 1) {
		system1.burst(sprinkler,brightWater,4);
	}
	else if (random == 2) {
		system1.burst(sprinkler,darkWater,1);
	}

	background.burst(backSpawner,bigDots,1);
}


void testApp::draw(){
	background.animate();
	system1.animate();
}


void testApp::keyPressed(int key){
	sprinkler.toggleOn();
}

void testApp::keyReleased(int key){}
void testApp::mouseMoved(int x, int y){}
void testApp::mouseDragged(int x, int y, int button){}
void testApp::mousePressed(int x, int y, int button){}
void testApp::mouseReleased(int x, int y, int button){}
void testApp::windowResized(int w, int h){}
void testApp::gotMessage(ofMessage msg){}
void testApp::dragEvent(ofDragInfo dragInfo){ }