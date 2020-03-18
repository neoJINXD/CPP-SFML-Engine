#pragma once
#include <SFML/Graphics.hpp>

namespace ui 
{
	enum BTN_STATE {
		BTN_IDLE = 0,
		BTN_HOVERED,
		BTN_CLICK
	};
	class Button
	{
	private:
		sf::RectangleShape button;
		sf::Font* font;
		sf::Text txt;

		sf::Color normal;
		sf::Color highlighted;
		sf::Color click;

		unsigned short state;

	public:
		Button(
			float x, 
			float y, 
			float width, 
			float height, 
			sf::Font* _font, 
			std::string _text
			);
		~Button();

		const bool isPressed() const;

		void update(const sf::Vector2f mousePos);

		void render(sf::RenderTarget* target);
	};

}

