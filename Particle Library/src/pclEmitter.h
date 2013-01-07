#pragma once

#include <vector>
#include <string>

class pclEmitter {

public:

	pclEmitter(std::string emitterShape = "point",double xPosition = 0,double yPosition = 0,double emitterSize1 = 0,double emitterSize2 = 0) : shape(emitterShape),x(xPosition),y(yPosition),size1(emitterSize1),size2(emitterSize2),on(true) {}

	double getMinX()	{return minX;}
	double getMinY()	{return minY;}
	double getMaxX()	{return maxX;}
	double getMaxY()	{return maxY;}
	double getSize1()	{return size1;}
	double getSize2()	{return size2;}
	double getX()		{return x;}
	double getY()		{return y;}
	std::string getShape()	{return shape;}

	void setMinX	(double min)		{minX = min;}
	void setMinY	(double min)		{minY = min;}
	void setMaxX	(double max)		{maxX = max;}
	void setMaxY	(double max)		{maxY = max;}
	void setSize1	(double size)		{size1 = size;}
	void setSize2	(double size)		{size2 = size;}
	void setX		(double newX)		{x = newX;}
	void setY		(double newY)		{y = newY;}
	void setShape	(std::string newShape)	{shape = newShape;}

	bool isOn() {return on;}
	void toggleOn() {on = !on;}
	void setState(bool state) {on = state;}

	void setSpeeds(double minXspeed = 0,double maxXspeed = 0,double minYspeed = 0,double maxYspeed = 0);




private:

	double minX,maxX,minY,maxY;

	std::string shape;

	double size1,size2;

	double x,y;

	bool on;

};