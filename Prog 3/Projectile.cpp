#include "Projectile.h"



Projectile::Projectile(std::string path, SDL_Renderer* renderer, int xPosition, int yPosition) : Sprite(path, renderer, xPosition, yPosition)
{
	moveSpeed = 4;
	yVelocity -= moveSpeed;
}


Projectile::~Projectile()
{
}

void Projectile::tick(std::vector<Sprite*> enemies)
{	
	moveRectY(yVelocity);
		for (int i = 0; i < enemies.size(); i++) {
		if (SDL_HasIntersection(&cRect->getRectangle(), &enemies[i]->getCRect()->getRectangle())) {
			enemies[i]->setDestroyable();
			setDestroyable();
		}
		if (cRect->getRectangle().x + iWidth > 800 || cRect->getRectangle().x < 0 || cRect->getRectangle().y + iHeight > 600 || cRect->getRectangle().y < 0) {
			setDestroyable();
		}
	}
}

bool Projectile::toBeDestroyed()
{
	return destroy;
}

Projectile * Projectile::getInstance(std::string path, SDL_Renderer * renderer, int xPosition, int yPosition)
{
	return new Projectile(path, renderer, xPosition, yPosition);
}
