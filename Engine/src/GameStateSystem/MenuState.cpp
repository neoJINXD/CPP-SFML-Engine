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

void statesystem::MenuState::init()
{
	if (!font.loadFromFile("resources/fonts/Blacklisted.ttf"))
	{
		printf("ERROR::MENUSTATE - FAILED TO LOAD FONT");
		exit(-1);
	}
}

statesystem::MenuState::MenuState(sf::RenderWindow* _win, std::map<std::string, int>* _validKeys) : State(_win, _validKeys)
{
	bgd.setSize(sf::Vector2f(win->getSize()));
	bgd.setFillColor(sf::Color::White);

	initKeybinds();
	init();

	testBTN = new ui::Button(100, 100, 1150, 50, &font, "Test");
}

statesystem::MenuState::~MenuState()
{
	delete testBTN;
	testBTN = nullptr;
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
	updateMousePos();
	updateInputs(dt);

	testBTN->update(mousePosView);

	printf("We In the menu\n");
	printf("We have ScreenPos (%i, %i)\nWe have WindowPos (%i, %i)\nWe have ViewPos (%i, %i)\n",
		mousePosScreen.x,
		mousePosScreen.y,
		mousePosWindow.x,
		mousePosWindow.y,
		mousePosView.x,
		mousePosView.y);
	system("cls");
}

void statesystem::MenuState::render(sf::RenderTarget* target)
{
	// render all items
	if (!target)
		target = win;
	//target->draw(bgd);
	testBTN->render(target);
}
