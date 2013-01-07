#pragma once

#include <vector>
#include <string>


class pclType {

public:
	pclType(std::string particleShape = "circle", double particleSize = 1, double redColor = 255, double greenColor = 255, double blueColor = 255, double extraSize = 0, double particleMass = 1) : shape(particleShape),size(particleSize),red(redColor),green(greenColor),blue(blueColor),size2(extraSize),changed(false),mass(particleMass) {init();}

	void initOriginals();
	void init();
	void setDecays(double alpha_decay = 0,double size_decay = 0,double red_increase = 0,double green_increase = 0,double blue_increase = 0);
	void setMass(double particleMass) {mass = particleMass;}

	double originalSize,originalSize2,originalX,originalY,originalXSpeed,originalYSpeed,originalRed,originalGreen,originalBlue,originalAlpha,originalAlphaDecay,originalSizeDecay;
	double originalRedIncrease,originalGreenIncrease,originalBlueIncrease;
	std::string originalShape;

	std::string shape;
	double size,size2;
	double x,y;
	double xSpeed,ySpeed;
	double red,green,blue,alpha;
	double alphaDecay,sizeDecay;
	double redIncrease,greenIncrease,blueIncrease;
	double mass;
	
	bool changed;

};