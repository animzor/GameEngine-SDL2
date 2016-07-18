#ifndef ENEMYSPRITE_H
#define ENEMYSPRITE_H
#include "Sprite.h"
#include <string>

class EnemySprite : public Sprite
{
public:
	~EnemySprite();
	static EnemySprite* getInstance(std::string path, SDL_Renderer* renderer, int xPosition, int yPosition);

private:
	EnemySprite(std::string path, SDL_Renderer* renderer, int xPosition, int yPosition);
};

#endif