#include "Button.h"

ui::Button::Button(
	float x, 
	float y, 
	float width, 
	float height, 
	sf::Font* _font, 
	std::string _text)
{
	state = BTN_IDLE;

	button.setPosition(sf::Vector2f(x, y));
	button.setSize(sf::Vector2f(width, height));

	font = _font;
	txt.setFont(*font);
	txt.setString(_text);
	txt.setFillColor(sf::Color::Black);
	txt.setCharacterSize(24);
	txt.setPosition(sf::Vector2f(
		button.getPosition().x + button.getSize().x / 2.f - txt.getGlobalBounds().width / 2.f,
		button.getPosition().y + button.getSize().y / 2.f - txt.getGlobalBounds().height / 2.f
	));

	normal = sf::Color(86, 86, 86);
	highlighted = sf::Color(201, 201, 201);
	click = sf::Color(20, 20, 20);

	button.setFillColor(normal);
}

ui::Button::~Button()
{
}

const bool ui::Button::isPressed() const
{
	return state == BTN_CLICK;
	//return false;
}

void ui::Button::update(const sf::Vector2f mousePos)
{
	//checks if mouse is hovering button or pressed on
	state = BTN_IDLE;
	if (button.getGlobalBounds().contains(mousePos))
	{
		state = BTN_HOVERED;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			state = BTN_CLICK;
			printf("button clicked!\n");
		}
	}

	//sets color based on state
	switch (state)
	{
	case BTN_IDLE:
		button.setFillColor(normal);
		break;
	case BTN_HOVERED:
		button.setFillColor(highlighted);
		break;
	case BTN_CLICK:
		button.setFillColor(click);
		break;
	default:
		button.setFillColor(sf::Color::Red);
		break;
	}

}

void ui::Button::render(sf::RenderTarget* target)
{
	target->draw(button);
	target->draw(txt);
}
