#include "CollisionRect.h"


CollisionRect::CollisionRect()
{
	cRect.x = 0;
	cRect.y = 0;
	cRect.w = 0;
	cRect.h = 0;

}
CollisionRect::CollisionRect(int x, int y, int w, int h)
{
	cRect.x = x;
	cRect.y = y;
	cRect.w = w;
	cRect.h = h;

}


CollisionRect::~CollisionRect()
{
}



void CollisionRect::setRectangle(int x, int y, int w, int h) {

	cRect.x = x;
	cRect.y = y;
	cRect.w = w;
	cRect.h = h;

}

SDL_Rect CollisionRect::getRectangle()
{
	return cRect;
}

void CollisionRect::setX(int x)
{
	cRect.x = x;
}

void CollisionRect::setY(int y)
{
	cRect.y = y;
}
