#include "stdafx.h"
#include <chrono>
#include "Ball.h"

Ball::Ball(Parameters& params) :radius(BALL_RADIUS)
{
	// Middle Of Racquet Position
	x = params.getWidth() / 2;
	y = params.getLength() - WALL_DISTANCE;

	// Random Initial Direction
	direction = 150.0 * (((rand() % 100) - 50.0) / 100.0);
	if (direction < 0)
	{
		direction += 360; // Angle must be between 0 to 360 Degrees
	}

	// Default
	velocity = params.getVelocity();
	color = params.getBallColor();
}

// Set Best Score & Reset Current Score On Goal
void setScore(int& current, int&highest)
{
	if (highest < current)
		highest = current;
	current = 0;
}

bool Ball::Collision_Handling(int Collision, double noise_range,Parameters& params,int& CurrentScore, int& BestScore)
{
	double angle_bias;
	bool goal = false;

	if (Collision > 0)
		angle_bias = noise_range * (((rand() % 100) - 50.0) / 100.0);

	switch (Collision)
	{
	case 1: // Right Collision
		direction = 360 - direction + angle_bias;
		break;

	case 16: // Racquet
	case 24: // Racquet + Goal == Racquet
		CurrentScore++;
	case 2: // Top Collision		
		direction = 180 - direction + angle_bias;
		break;

	case 20: // Racquet Left
		CurrentScore++;
	case 3: // Top Right Collision
		direction = 270 - direction + angle_bias;
		break;

	case 4: // Left Collision
		direction = 360 - direction + angle_bias;
		break;

	case 6: // Top Left Collision
		direction = 90 - direction + angle_bias;
		break;

	case 8: // Goal 
	case 9: // Goal (Goal + Right)
	case 12: // Goal (Goal + Left)
		setScore(CurrentScore, BestScore);

		x = params.getWidth() / 2;
		y = params.getLength() - WALL_DISTANCE;

		goal = true;

		direction = 150 * (((rand() % 100) - 50.0) / 100.0); // Random Initial Direction
		if (direction < 0)
		{
			direction += 360; // Angle must be between 0 to 360 Degrees
		}
		break;

	case 17: // Racquet Right
		CurrentScore++;
		direction = 120 - direction + angle_bias;
		break;

	default: // No Collision
		break;
	}

	// Set Ball Direction Between 0 to 360
	while (direction < 0)
	{
		direction += 360.0;
	}

	// Set Ball Direction Between 0 to 360
	if (direction >= 360)
		direction = direction - 360.0;

	return goal;
}


/*
Calculate The Ball's Distance Moved Over Specific Period Of Time.
The Timer Function Is Not Fixed And Is Different From Time To Time. 
For This Reason We Calculate The Exact Time Period Passed Since Last Timer Event.
*/
void Ball::Next_Step()
{
	// Sin & Cos Variable
	double Sin_Direction = sin(direction * Deg2Rad);
	double Cos_Direction = cos(direction * Deg2Rad);

	// Calculate Exact Time From Last Timer To Current Timer To Calculate The Exact Distance The Ball Moved
	SYSTEMTIME time;
	double ElapsedTime;
	double now = 0;
	static double LastTime = 0.0;

	GetSystemTime(&time);
	now = (double)time.wSecond + (double)time.wMilliseconds / 1000.0;
	ElapsedTime = now - LastTime;
	LastTime = now;

	// Calculate The Ball's Distance From Last Position
	double Distance = ElapsedTime * velocity;

	// Calculate Ball's Position Based On Distance
	double CalcX = x + Distance * Sin_Direction;
	double CalcY = y - Distance * Cos_Direction;
	x = CalcX;
	y = CalcY;
}