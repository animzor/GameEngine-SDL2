#include "GameEngine.h"






GameEngine::GameEngine(Environment* newEnv, Player* player)
{
	player1 = player;
	env = newEnv;
	frameTime = SDL_GetTicks();
	quit = false;

	while (!quit && env->getWindowBuilder()->getMainEvent()->type != SDL_QUIT) {
		env->getWindowBuilder()->begin();
		player1->getInput();
		player1->update();
		env->move();

		frameTime = SDL_GetTicks();

		env->update();

		env->getWindowBuilder()->end();

		if (player1->playerDead()) {
			std::cout << "game over!";
			SDL_Delay(5000);
			quit = true;
		}
		if (player1->playerWin()) {
			std::cout << "you win!";
			SDL_Delay(5000);
			quit = true;
		}

		if (SDL_GetTicks() - frameTime < MIN_FRAME_TIME) {
			SDL_Delay(MIN_FRAME_TIME - (SDL_GetTicks() - frameTime));
		}

	}

}


GameEngine::~GameEngine()
{
}




void GameEngine::setPlayer1(Player * player)
{
	player1 = player;
}