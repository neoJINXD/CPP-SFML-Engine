#include "Game.h"

void engine::Game::init()
{
	this->win = new sf::RenderWindow(sf::VideoMode(HEIGHT, WIDTH), "Title", sf::Style::Close | sf::Style::Titlebar);
    this->states.push(new statesystem::InGame(win));
}

engine::Game::Game() 
{
	this->init();
}

engine::Game::~Game() 
{
	delete win;
	win = nullptr;

    while (!states.empty())
    {
        delete states.top();
        states.pop();

    }
}


void engine::Game::update()
{
    // polling sfml events
    while (win->pollEvent(pollingEvnt)) {
        if (pollingEvnt.type == sf::Event::Closed) {
            win->close();
        }
    }
    if (!states.empty())
    {
        states.top()->update(dt);
        if (states.top()->getEnd())
        {
            states.top()->quit();
            delete states.top();
            states.pop();
        }
    }
    else {
        win->close();
    }
}

void engine::Game::render()
{
    // clears current buffer
    win->clear(background);

    // render items
    //win.draw(triangle);
    if (!states.empty())
        states.top()->render(win);

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


