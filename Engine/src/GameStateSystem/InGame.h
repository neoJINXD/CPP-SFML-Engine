#pragma once
#include "State.h"

namespace statesystem
{
	class InGame : public State
	{
	private:
	public:
		InGame(sf::RenderWindow* _win);
		virtual ~InGame();

		void end();

		void update(const float& dt);
		void render(sf::RenderTarget* target = nullptr);
	};

}

