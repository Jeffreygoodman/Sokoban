// CopyRight Jeffrey Goodman 2022
#include <math.h>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "sokoban.hpp"

int main(int argc, char* argv[]) {
std::ifstream myfile;
myfile.open(argv[1]);
Sokoban level;
myfile >> level;
level.createMap();
std::cout << level.getWidth() << " " << level.getHeight() << std::endl;
sf::RenderWindow window
(sf::VideoMode(level.getWidth()*64, level.getHeight()*64), "Sokoban level");
while (window.isOpen()) {
sf::Event event;
while (window.pollEvent(event)) {
switch(event.type) {
case sf::Event::Closed:
window.close();
break;
window.clear();
case sf::Event::KeyPressed:

switch(event.key.code) {
case sf::Keyboard::W:
if(!level.isWon())
level.movePlayer(UP);

break;
case sf::Keyboard::A:
if(!level.isWon())
level.movePlayer(LEFT);

break;
case sf::Keyboard::S:
if(!level.isWon())
level.movePlayer(DOWN);

break;
case sf::Keyboard::D:
if(!level.isWon())
level.movePlayer(RIGHT);

break;
case sf::Keyboard::R:
level.restartLevel();
break;
default:
break;
}


switch(event.key.code) {
case sf::Keyboard::R:
level.restartLevel();
break;
default:
break;
}

default:
break;
}
if (event.type == sf::Event::Closed)
window.close();
}
window.draw(level);
level.isWon();
window.display();
}
return 0;
}
