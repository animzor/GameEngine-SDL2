#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <vector>
#include "WindowBuilder.h"
#include "EnemySprite.h"
#include "Player.h"
#include <iostream>
#include "Environment.h"


class GameEngine
{
public:
	GameEngine(Environment* newEnv, Player* player);
	~GameEngine();

	void setPlayer1(Player* player);

private:
	Environment* env;
	static const int MIN_FRAME_TIME = 40;
	int frameTime;
	bool quit;
	Player* player1;

};
#endif