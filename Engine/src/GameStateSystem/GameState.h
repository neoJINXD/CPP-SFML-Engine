#pragma once
#include "State.h"
#include "../Entities/Entity.h"

namespace statesystem
{
	class GameState : public State
	{
	private:
		entity::Entity player;

		void initKeybinds();

	public:
		GameState(sf::RenderWindow* _win, std::map<std::string, int>* _validKeys);
		virtual ~GameState();


		void updateInputs(const float& dt);
		void quit();
		void update(const float& dt);
		void render(sf::RenderTarget* target = nullptr);
	};

}

