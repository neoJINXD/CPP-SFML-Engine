#pragma once
#include "State.h"

namespace statesystem
{
	class MenuState :
		public State
	{
	private:
		sf::RectangleShape bgd;

		void initKeybinds();

	public:
		MenuState(sf::RenderWindow* _win, std::map<std::string, int>* _validKeys);
		virtual ~MenuState();


		void updateInputs(const float& dt);
		void quit();
		void update(const float& dt);
		void render(sf::RenderTarget* target = nullptr);

	};

}

