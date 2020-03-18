#pragma once

#include <vector>
//#include <map>
#include <SFML/Graphics.hpp>
#include "../Entities/Entity.h"

namespace statesystem 
{
	class State
	{
	private:

	protected:
		bool ended;
		sf::RenderWindow* win;
		std::vector<sf::Texture*> textures;

		std::map<std::string, int>* validKeys;
		std::map<std::string, int> keybinds;

		sf::Vector2i mousePosScreen;
		sf::Vector2i mousePosWindow;
		sf::Vector2f mousePosView;

		virtual void initKeybinds() = 0;

	public:
		State(sf::RenderWindow* _win, std::map<std::string, int>* _validKeys);
		virtual ~State();

		const bool& getEnd() const;
		void checkEnd();

		virtual void updateInputs(const float& dt) = 0;
		virtual void updateMousePos();
		virtual void quit() = 0;
		virtual void update(const float& dt) = 0;
		virtual void render(sf::RenderTarget* target = nullptr) = 0;
	};
}

