#include "pclField.h"

pclField::pclField() {

}

pclField::pclField(double fieldStrength, double Xpos, double Ypos) {

	strength = fieldStrength;

	x = Xpos;
	y = Ypos;

	on = true;
}

pclField::pclField(std::string sh, double s1, double s2, double str, double newX, double newY) {

	shape = sh;

	size = s1;
	size2 = s2;

	strength = str;

	x = newX;
	y = newY;

	on = true;
}