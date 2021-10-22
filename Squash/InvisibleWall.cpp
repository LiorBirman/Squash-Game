#include "stdafx.h"
#include "InvisibleWall.h"

InvisibleWall::InvisibleWall()
{
}

InvisibleWall::InvisibleWall(Parameters& params)
{
	color = 2; // Gray
	retnoise = 0;

	// Position
	x1 = 0;
	y1 = params.getLength();
	x2 = params.getWidth();
	y2 = params.getLength();

	collision_type = 8;
}

// Return True If Ball Hit The Wall
int InvisibleWall::Collision(Ball& ball)
{
	if ((ball.getY() - BALL_RADIUS >= y1) && (ball.getX() >= x1) && (ball.getX() <= x2)) // Identify If The Ball Hit The Invisible Wall
	{
		// Sin & Cos Of The Angle Between "North" (From Racquet To Upper Wall) & Ball Direction
		double Sin_Direction = sin(ball.getDirection() * Deg2Rad);
		double Cos_Direction = cos(ball.getDirection() * Deg2Rad);

		// Limit & Set The Ball's Position On The Invisible Wall
		double CalcY = y2 - BALL_RADIUS;
		double Distance = (CalcY - ball.getY()) / Cos_Direction;
		double CalcX = ball.getX() - Distance * Sin_Direction;
		ball.setX(CalcX);
		ball.setY(CalcY);

	}

	// Check If The Ball Hit The Invisible Wall Below The Racquet
	if ((ball.getY() + FIXED_COLLISION_POSITION - BALL_RADIUS >= y1) && (ball.getX() >= x1) && (ball.getX() <= x2))
	{
		return collision_type;
	}
	else // No Collision
	{
		return 0;
	}
}
