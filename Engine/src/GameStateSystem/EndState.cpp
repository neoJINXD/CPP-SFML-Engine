#include "EndState.h"

void statesystem::EndState::initKeybinds()
{
	keybinds["CLOSE"] = validKeys->at("Escape");
}

void statesystem::EndState::init()
{
	float middle = win->getSize().x / 2.f;
	buttons["EXIT"] = new ui::Button(middle, 650, 150, 50, &font, "EXIT", ui::CENTER);
}

statesystem::EndState::EndState(sf::RenderWindow* _win, std::map<std::string, int>* _validKeys, std::stack<State*>* _states) : State(_win, _validKeys, _states)
{
	bgd.setSize(sf::Vector2f(win->getSize()));
	bgd.setFillColor(sf::Color::White);

	initKeybinds();
	init();
}

statesystem::EndState::~EndState()
{
	for (auto& i : buttons)
	{
		delete i.second;
	}
}

void statesystem::EndState::updateInputs(const float& dt)
{
	checkEnd();


	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		printf("Left mouse\n");
}

void statesystem::EndState::quit()
{
	printf("Ending End state\n");

}

void statesystem::EndState::update(const float& dt)
{
	updateMousePos();
	updateInputs(dt);

	for (auto& i : buttons)
	{
		i.second->update(mousePosView);
	}

	if (buttons["EXIT"]->isPressed())
		ended = true;

	printf("We In the End\n");
	printf("We have ScreenPos (%i, %i)\nWe have WindowPos (%i, %i)\nWe have ViewPos (%i, %i)\n",
		mousePosScreen.x,
		mousePosScreen.y,
		mousePosWindow.x,
		mousePosWindow.y,
		mousePosView.x,
		mousePosView.y);
	system("cls");
}

void statesystem::EndState::render(sf::RenderTarget* target)
{
	// render all items
	if (!target)
		target = win;
	//target->draw(bgd);
	for (auto& i : buttons)
	{
		i.second->render(target);
	}
}
