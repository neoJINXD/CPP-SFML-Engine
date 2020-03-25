#pragma once

#include "State.h"
#include "../UI/Button.h"

namespace statesystem
{
	class EndState:
		public State
	{
	private:
		sf::RectangleShape bgd;
		sf::Font font;
		std::map<std::string, ui::Button*> buttons;

		void initKeybinds();
		void init();

	public:
		EndState(sf::RenderWindow* _win, std::map<std::string, int>* _validKeys, std::stack<State*>* _states);
		virtual ~EndState();

		void updateInputs(const float& dt);
		void quit();
		void update(const float& dt);
		void render(sf::RenderTarget* target = nullptr);
	};

}

