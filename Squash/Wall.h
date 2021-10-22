#pragma once
#include "stdafx.h"
#include "Parameters.h"
#include "Ball.h"
#include <iostream>
using namespace std;

class Wall
{
public:

	// Getters
	double getX1() { return x1; }
	double getY1() { return y1; }
	double getX2() { return x2; }
	double getY2() { return y2; }
	int Get_x1_pixel(Parameters& params) { return ((int)((x1 * params.getWidthPixels()) / params.getWidth())); }
	int Get_x2_pixel(Parameters& params) { return ((int)((x2 * params.getWidthPixels()) / params.getWidth())); }
	int Get_y1_pixel(Parameters& params) { return ((int)((y1 * params.getLengthPixels()) / params.getLength())); }
	int Get_y2_pixel(Parameters& params) { return ((int)((y2 * params.getLengthPixels()) / params.getLength())); }

	virtual int Collision(Ball&) = 0;

protected:

	// Measured By Meters
	double x1;
	double x2;
	double y1;
	double y2;

	double retnoise; // For Random Return Direction (Measured By Angle)

	int collision_type;
};

