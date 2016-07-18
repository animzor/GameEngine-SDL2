#include "Player.h"




Player::Player(std::string path, WindowBuilder* wndwBuilder, Environment* env)
{
	this->env = env;
	moveSpeed = 4;
	xVel = 0;
	yVel = 0;

	this->wndwBuilder = wndwBuilder;

	playerSprite = PlayerSprite::getInstance(path, wndwBuilder->getRenderer(), 50, 450);
	env->addPlayer(playerSprite);
}

Player::~Player()
{
}

void Player::update()
{
	playerSprite->tick(xVel, yVel, moveSpeed, env->getEnemyList());
}

void Player::getInput()
{

	switch (wndwBuilder->getMainEvent()->type) {

	case SDL_KEYDOWN:
		switch (wndwBuilder->getMainEvent()->key.keysym.sym) {


		case SDLK_SPACE:
			shoot();
			break;

	/*	case SDLK_UP:
			yVel -= moveSpeed;
			update();
			break;

		case SDLK_DOWN:
			yVel += moveSpeed;
			update();
			break;*/

		case SDLK_RIGHT:
			xVel += moveSpeed;
			update();
			break;

		case SDLK_LEFT:
			xVel -= moveSpeed;
			update();
			break;

		default:
			break;
		}

	case SDL_KEYUP:
		switch (wndwBuilder->getMainEvent()->key.keysym.sym) {

	/*	case SDLK_UP:
			yVel = 0;
			break;

		case SDLK_DOWN:
			yVel = 0;			
			break;*/

		case SDLK_RIGHT:
			xVel = 0;			
			break;

		case SDLK_LEFT:
			xVel = 0;			
			break;

		default:
			break;
		}

	}


}

void Player::draw()
{

	playerSprite->draw();

}

void Player::shoot()
{
	if (env->getBulletList().size() < 3) {
		bullet = Projectile::getInstance("img/laser.png", wndwBuilder->getRenderer(), 0, 0);
		bullet->setRectX(playerSprite->getX() + (bullet->getX() / 2));
		bullet->setRectY(playerSprite->getY() - bullet->getY());
		env->addBullet(bullet);
	}
}

PlayerSprite* Player::getSprite()
{
	return playerSprite;
}

bool Player::playerDead()
{
	return playerSprite->playerDead();
}

bool Player::playerWin()
{
	return playerSprite->playerWin();;
}

