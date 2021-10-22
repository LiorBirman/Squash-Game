#include "stdafx.h"
#include "UpperWall.h"

UpperWall::UpperWall(Parameters& params)
{
	retnoise = params.getRetnoise(); // Default

	// Position
	x1 = 0;
	y1 = 0;
	x2 = params.getWidth();
	y2 = 0;

	collision_type = 2;
}

// Return True If Ball Hit The Wall
int UpperWall::Collision(Ball& ball)
{
	if ((ball.getY()-BALL_RADIUS) <= 0) // Identify If The Ball Hit The Upper Wall
	{
		// Sin & Cos Of The Angle Between "North" (From Racquet To Upper Wall) & Ball Direction
		double Sin_Direction = sin(ball.getDirection() * Deg2Rad);
		double Cos_Direction = cos(ball.getDirection() * Deg2Rad);

		// Limit & Set The Ball's Position On The Upper Wall
		double CalcY = 0 + BALL_RADIUS;
		double Distance = (CalcY - ball.getY()) / Cos_Direction;
		double CalcX = ball.getX() - Distance * Sin_Direction;
		ball.setX(CalcX);
		ball.setY(CalcY);

		return collision_type;
	}
	else // No Collision
	{
		return 0;
	}
}