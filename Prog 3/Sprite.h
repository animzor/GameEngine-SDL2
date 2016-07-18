#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
#include <string>
#include "CollisionRect.h"
#include <SDL_image.h>
#include <iostream>
#include <vector>

class Player;

class Sprite
{
public:

	Sprite(const Sprite& other) = delete;
	const Sprite& operator=(const Sprite& other) = delete;

	~Sprite();

	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;

	CollisionRect* getCRect();
	SDL_Rect getRect();

	void draw();
	void update();
	
	virtual void tick();
	virtual void tick(std::vector<Sprite*> anyVector);


	void setRectX(int x);
	void setRectY(int y);
	void moveRectX(int x);
	void moveRectY(int y);

	void setDestroyable();
	bool toBeDestroyed();
	bool collision(std::vector<Sprite*> spriteVector);


protected:
	Sprite(std::string path, SDL_Renderer* renderer, int xPosition, int yPosition);
	bool destroy;
	int moveSpeed;
	int xVelocity;
	int yVelocity;
	SDL_Renderer* renderer;
	CollisionRect* cRect;
	int iWidth, iHeight;
	float xPos, yPos;
	SDL_Texture* image;
	SDL_Rect rect;
};

#endif