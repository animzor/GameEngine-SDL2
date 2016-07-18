#include "GameEngine.h"
#include "Environment.h"
#include "Player.h"




int main(int argc, char *argv[])
{
	Environment* env = new Environment();
	Player* player = new Player("img/player.png", env->getWindowBuilder(), env);
	env->spawnEnemies("img/greenenemy.png", "img/blueenemy.png", "img/purpleenemy.png", 10, 0);
	GameEngine* engine = new GameEngine(env, player);
	return 0;
}