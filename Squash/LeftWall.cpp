#include "stdafx.h"
#include "LeftWall.h"

LeftWall::LeftWall(Parameters& params)
{
	retnoise = params.getRetnoise(); // Default
	
	// Position
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = params.getLength();

	collision_type = 4;
	
}

// Return True If Ball Hit The Wall
int LeftWall::Collision(Ball& ball)
{
	if ((ball.getX()-BALL_RADIUS) <= 0)  // Identify If The Ball Hit The Left Wall
	{
		// Sin & Cos Of The Angle Between "North" (From Racquet To Upper Wall) & Ball Direction
		double Sin_Direction = sin(ball.getDirection() * Deg2Rad);
		double Cos_Direction = cos(ball.getDirection() * Deg2Rad);

		// Limit & Set The Ball's Position On The Left Wall
		double CalcX = BALL_RADIUS;
		double Distance = (CalcX - ball.getX()) / Sin_Direction;
		double CalcY = ball.getY() - Distance * Cos_Direction;
		ball.setX(CalcX);
		ball.setY(CalcY);

		return collision_type;
	}
	else // No Collision
	{
		return 0;
	}
}
