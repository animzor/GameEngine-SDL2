#ifndef PLAYERSPRITE_H
#define PLAYERSPRITE_H
#include "Sprite.h"

class PlayerSprite : public Sprite
{
public:
	~PlayerSprite();

	void tick(int xVel, int yVel, int moveSpeed, std::vector<Sprite*> enemyVector);
	bool playerDead();
	bool playerWin();

	static PlayerSprite* getInstance(std::string path, SDL_Renderer* renderer, int xPosition, int yPosition);

private:
	PlayerSprite(std::string path, SDL_Renderer* renderer, int xPosition, int yPosition);
	bool dead;
	bool win;
};

#endif