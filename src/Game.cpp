#include "Game.hpp"

Game::Game() {
  win = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Tilt");
}

Game::~Game() {}

void Game::loop() {
  sf::Font *font = new sf::Font();
  font->loadFromFile("../resources/Blacklisted.ttf");
  sf::Text *txt = new sf::Text("REEEEE", *font, 100);
  txt->setPosition(400, 400);

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
    win->draw(*txt);

    // render
    win->display();
  }
  // Kill game
}