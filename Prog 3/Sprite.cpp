#include "Sprite.h"



Sprite::Sprite(std::string path, SDL_Renderer* renderer, int xPosition, int yPosition)
{

	this->renderer = renderer;
	this->xPos = xPosition;
	this->yPos = yPosition;

	xVelocity = 0;
	yVelocity = 0;

	destroy = false;


	image = IMG_LoadTexture(renderer, path.c_str());
	if (image == NULL) {
		std::cout << SDL_GetError() << std::endl;

	}

	//Get the dimensions of the image

	SDL_QueryTexture(image, NULL, NULL, &iWidth, &iHeight);

	//Set dimensions of the collision rectangle
	cRect = new CollisionRect(xPos, yPos, iWidth, iHeight);

	//Make destination rectangle same size as image
	rect.x = xPos;
	rect.y = yPos;
	rect.w = iWidth;
	rect.h = iHeight;
}


Sprite::~Sprite()
{

	delete cRect;

}

int Sprite::getX() const
{
	return rect.x;
}

int Sprite::getY() const
{
	return rect.y;
}

int Sprite::getWidth() const
{
	return iWidth;
}

int Sprite::getHeight() const
{
	return iHeight;
}

void Sprite::draw()
{
	SDL_RenderCopy(renderer, image, NULL, &rect);
	
}



CollisionRect* Sprite::getCRect() 
{
	return cRect;
}
SDL_Rect Sprite::getRect() 
{
	return rect;
}

void Sprite::update()
{
}

void Sprite::tick()
{
}

void Sprite::tick(std::vector<Sprite*> anyVector)
{
}


void Sprite::setRectX(int x)
{
	rect.x = x;
	cRect->setX(rect.x);
}

void Sprite::setRectY(int y)
{
	rect.y = y;
	cRect->setY(rect.y);
}

void Sprite::moveRectX(int x)
{
	rect.x += x;
	cRect->setX(rect.x);
}
void Sprite::moveRectY(int y)
{
	rect.y += y;
	cRect->setY(rect.y);
}

void Sprite::setDestroyable()
{
	destroy = true;
}

bool Sprite::toBeDestroyed()
{
	return destroy;
}

bool Sprite::collision(std::vector<Sprite*> spriteVector)
{
	for (int i = 0; i < spriteVector.size(); i++) {
		if (SDL_HasIntersection(&cRect->getRectangle(), &spriteVector[i]->getCRect()->getRectangle()) ||
			cRect->getRectangle().x + iWidth > 800 || cRect->getRectangle().x < 0 ||
			cRect->getRectangle().y + iHeight > 600 ||
			cRect->getRectangle().y < 0) {

			return true;
		}
	}

	return false;
}
