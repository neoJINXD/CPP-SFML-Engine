#pragma once

#include <vector>
//#include <map>
#include <SFML/Graphics.hpp>

namespace statesystem 
{
	class State
	{
	private:
		std::vector<sf::Texture*> textures;
		bool ended;


	protected:
		sf::RenderWindow* win;

		std::map<std::string, int>* validKeys;
		std::map<std::string, int> keybinds;

		virtual void initKeybinds() = 0;

	public:
		State(sf::RenderWindow* _win, std::map<std::string, int>* _validKeys);
		virtual ~State();

		const bool& getEnd() const;
		void checkEnd();

		virtual void updateInputs(const float& dt) = 0;
		virtual void quit() = 0;
		virtual void update(const float& dt) = 0;
		virtual void render(sf::RenderTarget* target = nullptr) = 0;
	};
}

