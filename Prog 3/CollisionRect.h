#ifndef COLLISIONRECT_H
#define COLLISIONRECT_H

#include <SDL.h>



class CollisionRect
{
public:
	CollisionRect();
	CollisionRect(int x, int y, int w, int h);
	~CollisionRect();
	void setRectangle(int x, int y, int w, int h);
	SDL_Rect getRectangle();
	void setX(int x);
	void setY(int y);
private:
	SDL_Rect cRect;
};

#endif