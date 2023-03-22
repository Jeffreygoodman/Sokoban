// CopyRight Jeffrey Goodman 2022

#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

enum Move {UP, LEFT, DOWN, RIGHT };
class Sokoban:public sf::Drawable {
 public:
Sokoban();
void movePlayer(Move direction);
friend std::istream & operator>> (std::istream& is, Sokoban& sokoban);
void createMap();
void restartLevel();
bool isWon() const;
int getHeight();
int getWidth();

 private:
int height;
int width;
std::vector<std::vector<char>> array;
std::vector<std::vector<char>> originalMap;
sf::Texture box;
sf::Texture player;
sf::Texture wall;
sf::Texture ground;
sf::Texture goal;
mutable sf::Sprite player_sprite;
mutable sf::Sprite box_sprite;
mutable sf::Sprite background_sprite;
virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
std::istream & operator>> (std::istream& is, Sokoban& sokoban);
