#include "InGame.h"
#include <stdio.h>

statesystem::InGame::InGame(sf::RenderWindow* _win) : State(_win)
{


}

statesystem::InGame::~InGame()
{
}

void statesystem::InGame::end()
{
}

void statesystem::InGame::update(const float& dt)
{
	//std::cout << "We In the game" << std::endl;
	printf("We in the game with %f power\n", dt);
}

void statesystem::InGame::render(sf::RenderTarget* target)
{
}
