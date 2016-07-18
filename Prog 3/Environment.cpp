#include "Environment.h"

Environment::Environment()
{
	turnEnemies = false;
	moveEnemyDown = false;
	enemyMoveSpeed = 2;
	wndwBuilder = new WindowBuilder("Space Invaders", 800, 600);
}

Environment::~Environment()
{
	delete wndwBuilder;
}

std::vector<Sprite*> Environment::getBulletList()
{
	return bullets;
}

std::vector<Sprite*> Environment::getEnemyList()
{
	return enemies;
}

void Environment::addEnemy(Sprite* enemySprite)
{

	enemies.push_back(enemySprite);

}

void Environment::addBullet(Sprite* bulletSprite)
{
	bullets.push_back(bulletSprite);
}

void Environment::addPlayer(Sprite * playerSprite)
{
	players.push_back(playerSprite);
}


void Environment::move()
{
	//move all bullets
	if (bullets.size() > 0) {
		for (Sprite* bullet : bullets) {
			bullet->tick(enemies);
		}
	}

	//movement of enemies
	if (enemies.size() > 0) {
		for (Sprite* enemy : enemies) {

			if (!turnEnemies) {
				enemy->moveRectX(enemyMoveSpeed);
			}
			else {
				enemy->moveRectX(-enemyMoveSpeed);
			}

			if (moveEnemyDown) {
				for (Sprite* enemy : enemies) {
					enemy->moveRectY(7);
				}
				moveEnemyDown = false;
			}
			
		}

		for (Sprite* enemy : enemies) {
			if (enemy->getX() + enemy->getWidth() > 800) {
				turnEnemies = true;
				moveEnemyDown = true;
			}
			if (enemy->getX() < 0) {
				turnEnemies = false;
				moveEnemyDown = true;
			}
		}

	}
}

void Environment::update()
{
	//if enemy is to be destroyed, erase it, otherwise draw it
	for (int i = enemies.size() - 1; i >= 0; i--) {
		if (enemies[i]->toBeDestroyed()) {
			enemies.erase(enemies.begin() + i);
		}
		else {
			enemies[i]->draw();
		}
	}
	//if bullet is to be destroyed, erase it, otherwise draw it
	for (int i = bullets.size() - 1; i >= 0; i--) {
		if (bullets[i]->toBeDestroyed()) {
			bullets.erase(bullets.begin() + i);

		}
		else {
			bullets[i]->draw();
		}
	}

	for (Sprite* p : players) {
		p->draw();
	}
}

WindowBuilder * Environment::getWindowBuilder()
{
	return wndwBuilder;
}

EnemySpawner * Environment::getSpawner()
{
	return spawner;
}

void Environment::spawnEnemies(std::string path1, std::string path2, std::string path3, int xPosition, int yPosition)
{
	int xPos = xPosition;

	for (int i = 0; i<10; i++) {

		addEnemy(EnemySprite::getInstance(path1, wndwBuilder->getRenderer(), xPos, yPosition));
		addEnemy(EnemySprite::getInstance(path1, wndwBuilder->getRenderer(), xPos, yPosition + 50));
		addEnemy(EnemySprite::getInstance(path2, wndwBuilder->getRenderer(), xPos, yPosition + 100));
		addEnemy(EnemySprite::getInstance(path2, wndwBuilder->getRenderer(), xPos, yPosition + 150));
		addEnemy(EnemySprite::getInstance(path3, wndwBuilder->getRenderer(), xPos, yPosition + 200));
		xPos += 60;
	}
}