#pragma once
#include "stdafx.h"
#include "Ball.h"
#include "InvisibleWall.h"
#include "LeftWall.h"
#include "RightWall.h"
#include "UpperWall.h"
#include "Wall.h"
#include "Parameters.h"
#include "Racquet.h"
#include "Score.h"
#include <windows.h>
#include <thread>

class Game
{
public:

	Game();
	~Game();

	bool Move(int&, int&);

	// Replaced With Serialization
	//void SaveGame();
	//void LoadGame();

	// Getters
	LeftWall& getLeftWall() { return *left; }
	RightWall& getRightWall() { return *right; }
	UpperWall& getUpperWall() { return *upper; }
	InvisibleWall& getInvisibleWall() { return *goal; }
	Racquet& getRacquetWall() { return *racquet; }
	Parameters& getParams() { return *params; }
	Parameters& getSavedParams() { return *saved_params; }
	Ball& getBall() { return *ball; }


private:
	Ball* ball;
	Parameters* params;
	Parameters* saved_params;
	LeftWall* left;
	RightWall* right;
	UpperWall* upper;
	InvisibleWall* goal;
	Racquet* racquet;

};

