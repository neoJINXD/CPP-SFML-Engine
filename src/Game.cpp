#include "Game.hpp"

Game::Game() { win = new sf::RenderWindow(sf::VideoMode(1200, 1200), "Tilt"); }

Game::~Game() {}

void Game::loop() {
  while (win->isOpen()) {
    sf::Event event;

    while (win->pollEvent(event)) {
      if (event.type == sf::Event::Closed) win->close();

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        win->close();
      }
    }

    // update
    win->clear(background);
    // win->draw(shape);

    // render
    win->display();
  }
}