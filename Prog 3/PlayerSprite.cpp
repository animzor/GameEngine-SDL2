#include "PlayerSprite.h"



PlayerSprite::PlayerSprite(std::string path, SDL_Renderer* renderer, int xPosition, int yPosition) : Sprite(path, renderer, xPosition, yPosition)
{
	dead = false;
	win = false;
	moveSpeed = 4;
}


PlayerSprite::~PlayerSprite()
{
}

void PlayerSprite::tick(int xVel, int yVel, int moveSpeed, std::vector<Sprite*> enemyVector)
{

	if (collision(enemyVector)) {
		dead = true;
	}
	if (enemyVector.size() == 0) {
		win = true;
	}

	int previousX = rect.x;
	
	moveRectX(xVel);
	cRect->setX(rect.x);

	if (cRect->getRectangle().x + iWidth > 800 || cRect->getRectangle().x < 0) {
		setRectX(previousX);
		cRect->setX(rect.x);
	}

	int previousY = rect.y;

	moveRectY(yVel);
	cRect->setY(rect.y);

	if (cRect->getRectangle().y + iHeight > 600 || cRect->getRectangle().y < 0) {
		setRectY(previousY);
		cRect->setY(rect.y);
	}

}

bool PlayerSprite::playerDead()
{
	return dead;
}

bool PlayerSprite::playerWin()
{
	return win;
}

PlayerSprite * PlayerSprite::getInstance(std::string path, SDL_Renderer * renderer, int xPosition, int yPosition)
{
	return new PlayerSprite(path, renderer, xPosition, yPosition);
}
