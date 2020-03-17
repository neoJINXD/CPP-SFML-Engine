#include "State.h"

statesystem::State::State(sf::RenderWindow* _win, std::map<std::string, int>* _validKeys)
{
	win = _win;
	ended = false;
	validKeys = _validKeys;

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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("CLOSE"))))
		ended = true;
}

