#include "MenuState.h"
#include <stdio.h>

void statesystem::MenuState::initKeybinds()
{
	keybinds["CLOSE"] = validKeys->at("Escape");
	/*keybinds["MOVE_UP"] = validKeys->at("W");
	keybinds["MOVE_LEFT"] = validKeys->at("A");
	keybinds["MOVE_DOWN"] = validKeys->at("S");
	keybinds["MOVE_RIGHT"] = validKeys->at("D");*/

}

statesystem::MenuState::MenuState(sf::RenderWindow* _win, std::map<std::string, int>* _validKeys) : State(_win, _validKeys)
{
	bgd.setSize(sf::Vector2f(win->getSize()));
	bgd.setFillColor(sf::Color::White);

	initKeybinds();
}

statesystem::MenuState::~MenuState()
{
}

void statesystem::MenuState::updateInputs(const float& dt)
{
	checkEnd();


	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		printf("Left mouse\n");
}

void statesystem::MenuState::quit()
{
	printf("Ending Menu state\n");
}

void statesystem::MenuState::update(const float& dt)
{
	updateInputs(dt);
	printf("We In the menu\n");
}

void statesystem::MenuState::render(sf::RenderTarget* target)
{
	// render all items
	if (!target)
		target = win;
	target->draw(bgd);
}
