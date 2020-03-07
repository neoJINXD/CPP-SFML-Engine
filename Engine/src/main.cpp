#include "Game.h"

#include <iostream>

int main() {
  /*Game game;
  std::cout << "re";
  game.loop();*/
    //sf::RenderWindow win(sf::VideoMode(1280, 720), "Title", sf::Style::Default);
    //win.setActive(true);

    //std::cout << glGetString(GL_VERSION) << std::endl;

    // create an array of 3 vertices that define a triangle primitive
    //sf::VertexArray triangle(sf::Triangles, 3);

    // define the position of the triangle's points
    //triangle[0].position = sf::Vector2f(10.f, 10.f);
    //triangle[1].position = sf::Vector2f(600.f, 10.f);
    //triangle[2].position = sf::Vector2f(600.f, 600.f);

    // define the color of the triangle's points
    //triangle[0].color = sf::Color(255,0,0,128);
    //triangle[1].color = sf::Color::Blue;
    //triangle[2].color = sf::Color::Green;

    engine::Game gam;
    gam.loop();

    system("pause");
    return 0;
}
