#ifndef PLAYER_H
#define PLAYER_H
#include "Environment.h"
#include "WindowBuilder.h"
#include "PlayerSprite.h"
#include "Projectile.h"

class Player
{
public:
	Player(std::string path, WindowBuilder* wndwBuilder, Environment* env);
	~Player();

	void getInput();
	void update();
	void draw();
	void shoot();
	PlayerSprite* getSprite();
	bool playerDead();
	bool playerWin();

private:
	Environment* env;
	int xVel, yVel, moveSpeed;
	Projectile* bullet;
	WindowBuilder* wndwBuilder;
	PlayerSprite* playerSprite;
	
};

#endif