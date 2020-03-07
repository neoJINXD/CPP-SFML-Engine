#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>

class Game {
private:
      const int HEIGHT = 1280;
      const int WIDTH = 720;
      const sf::Color background = sf::Color::Cyan;

      sf::RenderWindow *win;
      sf::Event pollingEvnt;

      void init();
 

public:

      Game();
      ~Game();


      void preload();
      void setup();
      void update();
      void render();

      void loop();
};
