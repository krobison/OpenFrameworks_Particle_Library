#pragma once

#include <vector>
#include <string>

class pclField {

public:

	pclField();
	pclField(double fieldStrength, double Xpos, double Ypos);
	pclField(std::string sh, double s1, double s2, double str, double newX, double newY);

	std::string shape;

	double size,size2;

	double strength;

	double x,y;

	bool on;

};