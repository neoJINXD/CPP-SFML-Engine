#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>

class Game {
 public:
  Game();
  ~Game();
  void loop();

 private:
  const int HEIGHT = 800;
  const int WIDTH = 800;
  sf::RenderWindow *win;
  const sf::Color background = sf::Color::Cyan;
};

#endif