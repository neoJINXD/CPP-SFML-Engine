#include "Game.h"

void Game::init()
{
	this->win = new sf::RenderWindow(sf::VideoMode(HEIGHT, WIDTH), "Title", sf::Style::Close | sf::Style::Titlebar);
}

Game::Game() 
{
	this->init();
}

Game::~Game() 
{
	delete win;
	win = nullptr;
}


void Game::update()
{
    // polling sfml events
    while (win->pollEvent(pollingEvnt)) {
        if (pollingEvnt.type == sf::Event::Closed || pollingEvnt.key.code == sf::Keyboard::Escape) {
            win->close();
        }
    }
}

void Game::render()
{
    // clears current buffer
    win->clear(background);

    // render items
    //win.draw(triangle);

    // swaps buffers
    win->display();
}

void Game::loop()
{
    while (win->isOpen()) {
        this->update();
        this->render();
    }
}


