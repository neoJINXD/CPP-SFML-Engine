#include "State.h"

statesystem::State::State(sf::RenderWindow* _win)
{
	win = _win;
	ended = false;
}

statesystem::State::~State()
{
}

const bool& statesystem::State::getEnd() const
{
	return ended;
}

void statesystem::State::checkEnd()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		ended = true;
}

