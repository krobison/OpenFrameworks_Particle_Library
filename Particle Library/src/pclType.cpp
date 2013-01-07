#include "pclType.h"

void pclType::init() {
	initOriginals();
	setDecays();
}

void pclType::initOriginals() {
	originalShape		= shape;
	originalSize		= size;
	originalRed			= red;
	originalGreen		= green;
	originalBlue		= blue;
	originalXSpeed		= 0;
	originalYSpeed		= 0;
	originalAlpha		= 0;
}

void pclType::setDecays(double alpha_decay,double size_decay,double red_increase,double green_increase,double blue_increase) {
	alphaDecay		= alpha_decay;
	sizeDecay		= size_decay;
	redIncrease		= red_increase;
	greenIncrease	= green_increase;
	blueIncrease	= blue_increase;

	originalAlphaDecay		= alphaDecay;
	originalSizeDecay		= sizeDecay;
	originalRedIncrease		= redIncrease;
	originalGreenIncrease	= greenIncrease;
	originalBlueIncrease	= blueIncrease;
}
