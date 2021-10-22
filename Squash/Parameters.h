#pragma once
#include "stdafx.h"
#include <iostream>
using namespace std;


#define WALL_DISTANCE 0.2
#define BALL_RADIUS 0.12
#define WALL_WIDTH 10
#define FIXED_COLLISION_POSITION 0.1

#define RANDOM_INITIAL_ANGLE 70.0 //    +/- 35 Degrees
#define deltaT 0.3 // sec
#define Deg2Rad (3.14159265359 / 180.0) // Convret Degrees to Radians

class Parameters : public CObject
{
public:
	// Constructor
	Parameters();

	// Copy constructor & Operator=
	Parameters(const Parameters&);
	Parameters& operator=(const Parameters&);

	// Getters
	double getLength() { return pitchlength; }
	double getWidth() { return pitchwidth; }
	double getVelocity() { return velocity; }
	double getRetnoise() { return retnoise; }
	int getRacquetColor() { return racquetcolor; }
	int getLeftColor() { return leftcolor; }
	int getRightColor() { return rightcolor; }
	int getUpperColor() { return uppercolor; }
	int getBallColor() { return ballcolor; }
	double getRacquetSize() { return racquetsize; }
	int getLengthPixels() { return length_pixels; }
	int getWidthPixels() { return width_pixels; }

	// Setters
	void setRacquetSize(double& s) { racquetsize = s; }
	void setLength(double& l) { pitchlength = l; }
	void setWidth(double& w) { pitchwidth = w; }
	void setVelocity(double& v) { velocity = v; }
	void setRetnoise(double& r) { retnoise = r; }
	void setRacquetColor(int& c) { racquetcolor = c; }
	void setLeftColor(int& c) { leftcolor = c; }
	void setRightColor(int& c) { rightcolor = c; }
	void setUpperColor(int& c) { uppercolor = c; }
	void setBallColor(int& c) { ballcolor = c; }

	DECLARE_SERIAL(Parameters)
	virtual void serialize(CArchive&);

private:

	double pitchlength;
	double pitchwidth;

	double velocity;
	double retnoise;

	int racquetcolor;
	int leftcolor;
	int rightcolor;
	int uppercolor;
	int ballcolor;
	double racquetsize;

	int length_pixels;
	int width_pixels;
};

