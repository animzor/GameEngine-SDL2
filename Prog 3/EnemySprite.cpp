#include "EnemySprite.h"

EnemySprite::EnemySprite(std::string path, SDL_Renderer* renderer, int xPosition, int yPosition) : Sprite(path, renderer, xPosition, yPosition)
{
}


EnemySprite::~EnemySprite()
{
}


EnemySprite * EnemySprite::getInstance(std::string path, SDL_Renderer * renderer, int xPosition, int yPosition)
{
	return new EnemySprite(path, renderer, xPosition, yPosition);
}
