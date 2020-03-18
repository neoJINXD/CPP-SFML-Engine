#pragma once
#include "State.h"
#include "../UI/Button.h"

namespace statesystem
{
	class MenuState :
		public State
	{
	private:
		sf::RectangleShape bgd;
		sf::Font font;
		std::map<std::string, ui::Button*> buttons;

		//ui::Button* testBTN;

		void initKeybinds();
		void init();

	public:
		MenuState(sf::RenderWindow* _win, std::map<std::string, int>* _validKeys);
		virtual ~MenuState();


		void updateInputs(const float& dt);
		void quit();
		void update(const float& dt);
		void render(sf::RenderTarget* target = nullptr);

	};

}

