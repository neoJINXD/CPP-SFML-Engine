#include "Game.h"

void engine::Game::init()
{
	this->win = new sf::RenderWindow(sf::VideoMode(HEIGHT, WIDTH), "Title", sf::Style::Close | sf::Style::Titlebar);
}

engine::Game::Game() 
{
	this->init();
}

engine::Game::~Game() 
{
	delete win;
	win = nullptr;
}


void engine::Game::update()
{
    // polling sfml events
    while (win->pollEvent(pollingEvnt)) {
        if (pollingEvnt.type == sf::Event::Closed || pollingEvnt.key.code == sf::Keyboard::Escape) {
            win->close();
        }
    }
}

void engine::Game::render()
{
    // clears current buffer
    win->clear(background);

    // render items
    //win.draw(triangle);

    // swaps buffers
    win->display();
}

void engine::Game::loop()
{
    while (win->isOpen()) {
        dt = dtClock.restart().asSeconds();
        this->update();
        this->render();
    }
}


