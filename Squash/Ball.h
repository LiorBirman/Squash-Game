#pragma once
#include "stdafx.h"
#include "Parameters.h"
#include "Score.h"
#include <stdio.h>

class Ball
{
public:

	Ball(Parameters&);

	bool Collision_Handling(int, double, Parameters&, int&, int&);
	void Next_Step(); // Calculates the ball's next step

	// Getters
	int getcolor() { return color; }
	double getX() { return x; }
	double getY() { return y; }
	double getDirection() { return direction; }
	int Get_Radius_Pixel(Parameters& params) { return ((int)((radius * params.getWidthPixels()) / params.getWidth())); }
	int Get_x_pixel(Parameters& params) { return ((int)((x * params.getWidthPixels()) / params.getWidth())); }
	int Get_y_pixel(Parameters& params) { return ((int)((y * params.getWidthPixels()) / params.getWidth())); }

	// Setters
	void setVelocity(double vel) { velocity = vel; }
	void setX(double new_x) { x = new_x; }
	void setY(double new_y) { y = new_y; }
	void setDirection(double new_direction) { direction = new_direction; }

private:

	double x;
	double y;
	const double radius;
	double direction;
	double velocity;
	int color;
};