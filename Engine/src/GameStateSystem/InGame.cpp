#include "InGame.h"
#include <stdio.h>

statesystem::InGame::InGame(sf::RenderWindow* _win) : State(_win)
{


}

statesystem::InGame::~InGame()
{
}

void statesystem::InGame::updateKeyInputs(const float& dt)
{
	checkEnd();
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		printf("Left mouse\n");
}

void statesystem::InGame::quit()
{
	printf("Ending inGame state\n");
}

void statesystem::InGame::update(const float& dt)
{
	updateKeyInputs(dt);
	//std::cout << "We In the game" << std::endl;
	//printf("We in the game with %f power\n", dt);
}

void statesystem::InGame::render(sf::RenderTarget* target)
{
	// render all items
}
