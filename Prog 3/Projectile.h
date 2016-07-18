#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Sprite.h"

class Projectile : public Sprite
{
public:
	~Projectile();

	void Projectile::tick(std::vector<Sprite*> enemies);
	bool toBeDestroyed();

	static Projectile* getInstance(std::string path, SDL_Renderer* renderer, int xPosition, int yPosition);

private:
	Projectile(std::string path, SDL_Renderer* renderer, int xPosition, int yPosition);
	bool destroy;

};

#endif