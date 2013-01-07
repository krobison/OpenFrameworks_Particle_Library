#include "pclSystem.h"
#include "ofMain.h"

void pclSystem::animate() {
	
	double x,y,d,theta,force;
	
	for (int i = 0;i < particles.size();i++) {
		for (int j = 0;j < fields.size();j++) {
				y = abs(particles[i].y-fields[j].y);
				x = abs(particles[i].x-fields[j].x);
				d = sqrt(pow(abs(particles[i].x-fields[j].x),2)+pow(abs(particles[i].y-fields[j].y),2));
				theta = asin(y/d);
				force = (fields[j].strength*particles[i].mass)/(pow(d,2));

				if (particles[i].x > fields[j].x) {
					particles[i].xSpeed -= force*cos(theta);
				}
				else{
					particles[i].xSpeed += force*cos(theta);
				}

				if (particles[i].y > fields[j].y) {
					particles[i].ySpeed -= force*sin(theta);
				}
				else{
					particles[i].ySpeed += force*sin(theta);
				}
		}
		particles[i].x += particles[i].xSpeed;
		particles[i].y += particles[i].ySpeed;

		particles[i].red += particles[i].redIncrease;
		particles[i].blue += particles[i].blueIncrease;
		particles[i].green += particles[i].greenIncrease;

		particles[i].alpha += particles[i].alphaDecay;
		if (particles[i].size > 0) {
			particles[i].size  -= particles[i].sizeDecay;
			if (particles[i].size < 0) {
				particles[i].size = 0;
			}
		}
	
		particles[i].ySpeed += gravityY;
		particles[i].xSpeed += gravityX;


		if (particles[i].shape == "circle") {
			ofEnableAlphaBlending();
			ofSetColor(particles[i].red,particles[i].green,particles[i].blue,255-particles[i].alpha);
			ofFill();
			ofCircle(particles[i].x,particles[i].y,particles[i].size);
		}
		else if (particles[i].shape == "square") {
			ofEnableAlphaBlending();
			ofSetColor(particles[i].red,particles[i].green,particles[i].blue,255-particles[i].alpha);
			ofFill();
			ofRect(particles[i].x,particles[i].y,particles[i].size,particles[i].size);
		}
		else if (particles[i].shape == "hor_line") {
			ofEnableAlphaBlending();
			ofSetColor(particles[i].red,particles[i].green,particles[i].blue,255-particles[i].alpha);
			ofFill();
			ofLine(particles[i].x,particles[i].y,particles[i].x+particles[i].size,particles[i].y);
		}
		else if (particles[i].shape == "circle_hollow") {
			ofEnableAlphaBlending();
			ofSetColor(particles[i].red,particles[i].green,particles[i].blue,255-particles[i].alpha);
			ofNoFill();
			ofCircle(particles[i].x,particles[i].y,particles[i].size);
		}
		else if (particles[i].shape == "square_hollow") {
			ofEnableAlphaBlending();
			ofSetColor(particles[i].red,particles[i].green,particles[i].blue,255-particles[i].alpha);
			ofNoFill();
			ofRect(particles[i].x,particles[i].y,particles[i].size,particles[i].size);
		}
	}

	for (int i = 0;i < particles.size();i++) {
		if (particles[i].alpha > 255) {
			vector<pclType>::iterator loc = particles.begin();
			particles.erase(loc+i);
		}
	}
	for (int i = 0;i < particles.size();i++) {
		if ( (abs(particles[i].xSpeed) > 35)||(abs(particles[i].ySpeed) > 35) ) {
			vector<pclType>::iterator loc = particles.begin();
			particles.erase(loc+i);
		}
	}
	for (int i = 0;i < particles.size();i++) {
		for (int j = 0;j < fields.size();j++) {
			y = abs(particles[i].y-fields[j].y);
			x = abs(particles[i].x-fields[j].x);
			if ((x < 10)&&(y<10)) {
				vector<pclType>::iterator loc = particles.begin();
				particles.erase(loc+i);
			}
		}
	}

}


void pclSystem::burst(pclEmitter &emit, pclType &part,int amount) {
if (emit.isOn()) {
	if(emit.getShape() == "point") {
		for (int i = 0;i<amount;i++) {
			addParticle(part);
			part.x = emit.getX();
			part.y = emit.getY();
			part.xSpeed = ofRandom(emit.getMinX(),emit.getMaxX());
			part.ySpeed = ofRandom(emit.getMinY(),emit.getMaxY());

		}
	}

	if(emit.getShape() == "rect") {
		for (int i = 0;i<amount;i++) {
			addParticle(part);
			part.x = emit.getX()+rand()%int(emit.getSize1());
			part.y = emit.getY()+rand()%int(emit.getSize2());
			part.xSpeed = ofRandom(emit.getMinX(),emit.getMaxX());
			part.ySpeed = ofRandom(emit.getMinY(),emit.getMaxY());
		}
	}
}
}