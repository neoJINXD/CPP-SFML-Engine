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
		bool ended;

	public:
		State(sf::RenderWindow* _win);
		virtual ~State();

		const bool& getEnd() const;
		void checkEnd();

		virtual void updateKeyInputs(const float& dt) = 0;
		virtual void quit() = 0;
		virtual void update(const float& dt) = 0;
		virtual void render(sf::RenderTarget* target = nullptr) = 0;
	};
}

