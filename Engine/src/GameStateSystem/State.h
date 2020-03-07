#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

namespace statesystem 
{
	class State
	{
	private:
		sf::RenderWindow* win;
		std::vector<sf::Texture*> textures;

	public:
		State(sf::RenderWindow* _win);
		virtual ~State();

		virtual void end() = 0;

		virtual void update(const float& dt) = 0;
		virtual void render(sf::RenderTarget* target = nullptr) = 0;
	};
}

