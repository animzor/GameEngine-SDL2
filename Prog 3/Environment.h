#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <vector>
#include "Sprite.h"
#include "WindowBuilder.h"
#include "EnemySprite.h"
class EnemySpawner;


class Environment
{
public:
	Environment();
	~Environment();

	void spawnEnemies(std::string path1, std::string path2, std::string path3, int xPosition, int yPosition);
	std::vector<Sprite*> getBulletList();
	std::vector<Sprite*> getEnemyList();
	void addEnemy(Sprite* enemySprite);
	void addBullet(Sprite* bulletSprite);
	void addPlayer(Sprite* playerSprite);
	void move();
	void update();
	WindowBuilder* getWindowBuilder();
	EnemySpawner * getSpawner();

private:
	bool turnEnemies;
	bool moveEnemyDown;
	int enemyMoveSpeed;
	EnemySpawner* spawner;
	WindowBuilder* wndwBuilder;
	std::vector<Sprite*> players;
	std::vector<Sprite*> enemies;
	std::vector<Sprite*> bullets;
};

#endif