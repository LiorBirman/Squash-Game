#include "stdafx.h"
#include "Racquet.h"

Racquet::Racquet(Parameters& params)
{
	retnoise = params.getRetnoise(); // Default

	// Position (Lower Middle Of Pitch)
	x1 = (params.getWidth() / 2) - (params.getRacquetSize());
	y1 = (params.getLength() - WALL_DISTANCE);
	x2 = (params.getWidth() / 2) + (params.getRacquetSize());
	y2 = (params.getLength() - WALL_DISTANCE);

	collision_type = 16;
}

void Racquet::MoveLeftRight(double x_step)
{
	x1 += x_step;
	x2 += x_step;
}
