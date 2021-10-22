#include "stdafx.h"
#include "Parameters.h"

IMPLEMENT_SERIAL(Parameters, CObject,1)

Parameters::Parameters()
{
	// Pitch Size In Meters
	pitchlength = 10;
	pitchwidth = 10;

	// Pitch Size in Pixels
	length_pixels = 800;
	width_pixels = (int)(length_pixels / pitchlength * pitchwidth);

	velocity = 8.0; // Meter Per Sec

	ballcolor = 4; // Red
	uppercolor = 0; // Black
	racquetcolor = 0; // Black
	rightcolor = 0; // Black
	leftcolor = 0; // Black

	retnoise = 0; // Degrees

	racquetsize = 0.5; // Meter
}

Parameters::Parameters(const Parameters& p)
{
	this->ballcolor = p.ballcolor;
	this->velocity = p.velocity;
	this->uppercolor = p.uppercolor;
	this->racquetcolor = p.racquetcolor;
	this->rightcolor = p.rightcolor;
	this->leftcolor = p.leftcolor;
	this->retnoise = p.retnoise;
	this->length_pixels = p.length_pixels;
	this->width_pixels = p.width_pixels;
	this->pitchlength = p.pitchlength;
	this->pitchwidth = p.pitchwidth;
}

Parameters& Parameters::operator=(const Parameters& p)
{
	this->ballcolor = p.ballcolor;
	this->velocity = p.velocity;
	this->uppercolor = p.uppercolor;
	this->racquetcolor = p.racquetcolor;
	this->rightcolor = p.rightcolor;
	this->leftcolor = p.leftcolor;
	this->retnoise = p.retnoise;
	this->length_pixels = p.length_pixels;
	this->width_pixels = p.width_pixels;
	this->pitchlength = p.pitchlength;
	this->pitchwidth = p.pitchwidth;

	return *this;
}

void Parameters::serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << velocity << ballcolor << uppercolor << racquetcolor << rightcolor << leftcolor << retnoise;
	}
	else
	{
		ar >> velocity >> ballcolor >> uppercolor >> racquetcolor >> rightcolor >> leftcolor >> retnoise;
	}
}
