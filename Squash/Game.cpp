#include "stdafx.h"
#include "Game.h"
#include <stdio.h>

Game::Game()
{
	params = new Parameters;
	saved_params = new Parameters;
	goal = new InvisibleWall(*params);
	left = new LeftWall(*params);
	right = new RightWall(*params);
	upper = new UpperWall(*params);
	racquet = new Racquet(*params);
	ball = new Ball(*params);
}


Game::~Game()
{
	delete goal;
	delete ball;
	delete left;
	delete right;
	delete upper;
	delete racquet;
	delete params;
	delete saved_params;
}


bool Game::Move(int& CurrentScore, int& BestScore)
{
	int Collision;

		ball->Next_Step(); // Calculate Next Step Position

		// Calculate Current Collision
		Collision = right->Collision(*ball) | upper->Collision(*ball) | left->Collision(*ball) | goal->Collision(*ball);
		Collision = Collision | racquet->Collision(*ball);

		// Check If Goal
		bool End_Of_Game = ball->Collision_Handling(Collision, params->getRetnoise(), *params, CurrentScore, BestScore);

		return End_Of_Game;
}



// Replaced With Serialization
//// Save All Dynamic Parameters To File
//void Game::SaveGame()
//{
//	FILE * handler;
//	errno_t error;
//	error = fopen_s(&handler, "Saved Parameters.txt", "w+");
//
//	if (error == 0)
//	{
//		fprintf(handler, "%lf %lf %d %d %d %d %d", params->getVelocity(), params->getRetnoise(), params->getRacquetColor(),
//		params->getLeftColor(), params->getRightColor(), params->getUpperColor(), params->getBallColor());
//	}
//
//	fclose(handler);
//}
//


// Replaced With Serialization
//// Scans All Dynamic Parameters From File
//void Game::LoadGame()
//{
//	FILE * handler;
//	errno_t error;
//	error = fopen_s(&handler, "Saved Parameters.txt", "r");
//
//	double velocity;
//	double retnoise;
//	int racquetcolor;
//	int leftcolor;
//	int rightcolor;
//	int uppercolor;
//	int ballcolor;
//
//	if (error != 0)
//		return;
//
//	else
//	{
//		if (!feof(handler))
//		{
//			error = fscanf_s(handler, "%lf %lf %d %d %d %d %d", &velocity, &retnoise, &racquetcolor, &leftcolor, &rightcolor, &uppercolor, &ballcolor);
//		}
//	}
//
//	if (error == EOF || error == 0)
//	{
//		fclose(handler);
//		return;
//	}
//	params->setVelocity(velocity);
//	params->setRetnoise(retnoise);
//	params->setRacquetColor(racquetcolor);
//	params->setLeftColor(leftcolor);
//	params->setRightColor(rightcolor);
//	params->setUpperColor(uppercolor);
//	params->setBallColor(ballcolor);
//
//	fclose(handler);
//}
