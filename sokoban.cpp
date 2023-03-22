// CopyRight Jeffrey Goodman 2022
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>
#include <algorithm>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "sokoban.hpp"

Sokoban::Sokoban() {
auto errormsg = [] (const std::string& msg) {
std::cout << "could not load " << msg << " texture" << std::endl;
};

if (!box.loadFromFile("crate_03.png")) {
errormsg("box");
}

if (!wall.loadFromFile("block_06.png")) {
errormsg("wall");
}

if (!player.loadFromFile("player_05.png")) {
errormsg("player");
}

if (!ground.loadFromFile("ground_01.png")) {
errormsg("ground");
}

if (!goal.loadFromFile("ground_04.png")) {
errormsg("goal");
}
}
bool Sokoban::isWon() const {
int checkPoint = 0;
std::vector<std::vector<char>> ::const_iterator it;
for (it = array.begin(); it != array.end(); it++) {
    if (find(it->begin(), it->end(), '$') != it->end()) {
        checkPoint++;
    }
}

if (checkPoint == 2)
return true;
else
return false;
}

void Sokoban:: movePlayer(Move direction) {
for(unsigned int i = 0; i < array.size(); i++) {
for(unsigned int j = 0; j < array[i].size(); j++) {
if (array[i][j] == '%') {
if (direction == UP) {
if (array[i-1][j] == '#') {
return;
}
if(array[i-2][j] == '#'&& array[i-1][j] == 'O')  {
return;
}
if (array[i-1][j] == 'O') {
if (array[i-2][j] != '#' && array[i-2][j] != 'O') {
array[i-2][j] = 'O';
array[i-1][j] = '@';
array[i][j] = '*';
}
}
array[i-1][j] = '@';
array[i][j] = '*';
}
if (direction == DOWN) {
if (array[i+1][j] == '#') {
return;
}
if(array[i+2][j] == '#'&& array[i+1][j] == 'O')  {
return;
}
if (array[i+1][j] == 'O') {
if (array[i+2][j] != '#' && array[i+2][j] != 'O') {
array[i+2][j] = 'O';
array[i+1][j] = '@';
array[i][j] = '*';
    }
}
array[i+1][j] = '@';
array[i][j] = '*';
}
if (direction == LEFT) {
if (array[i][j-1] == '#') {
return;
}
if(array[i][j-2] == '#'&& array[i][j-1] == 'O') {
    return;
}
if (array[i][j-1] == 'O') {
if (array[i][j-2] != '#' && array[i][j-2] != 'O') {
array[i][j-2] = 'O';
array[i][j-1] = '@';
array[i][j] = '*';
    }
}
array[i][j-1] = '@';
array[i][j] = '*';
}
if (direction == RIGHT) {
if (array[i][j+1] == '#') {
return;
}
if(array[i][j+2] == '#'&& array[i][j+1] == 'O') {
    return;
}
if (array[i][j+1] == 'O') {
if (array[i][j+2] != '#' && array[i][j+2] != 'O') {
array[i][j+2] = 'O';
array[i][j+1] = '@';
array[i][j] = '*';
}
}
array[i][j+1] = '@';
array[i][j] = '*';
}
return;
}
// cases for player when not standing in goal
if (array[i][j] == '@') {
if (direction == UP) {
if (array[i-1][j] == '#') {
return;
}
if (array[i-2][j] == '*'&& array[i-1][j] == 'O') {
array[i-2][j] = '$';
array[i-1][j] = '@';
array[i][j] = '.';
}
if (array[i-1][j] == 'O') {
if (array[i-2][j] != '#' && array[i-2][j] != 'O') {
array[i-2][j] = 'O';
array[i-1][j] = '@';
array[i][j] = '.';
} else {
return;
}
}
if (array[i-1][j] == '$') {
array[i-2][j] = 'O';
array[i-1][j] = '%';
array[i][j] = '.';
}
if (array[i-1][j] == '*') {
array[i-1][j] = '%';
array[i][j] = '.';
}
if (array[i-1][j] == '.') {
array[i-1][j] = '@';
array[i][j] = '.';
}
}
if (direction == DOWN) {  // DOWN
if (array[i+1][j] == '#') {
return;
}
if (array[i+1][j] == '.') {
array[i+1][j] = '@';
array[i][j] = '.';
}
if (array[i+1][j] == '*') {
array[i+1][j] = '%';
array[i][j] = '.';
}
if (array[i+2][j] == '*'&& array[i+1][j] == 'O') {
array[i+2][j] = '$';
array[i+1][j] = '@';
array[i][j] = '.';
}
if (array[i+1][j] == 'O') {
if (array[i+2][j] != '#' && array[i+2][j] != 'O') {
array[i+2][j] = 'O';
array[i+1][j] = '@';
array[i][j] = '.';
} else {
return;
}
}

if (array[i+1][j] == '$') {
array[i+2][j] = 'O';
array[i+1][j] = '%';
array[i][j] = '.';
}
}
if (direction == RIGHT) {  // RIGHT
if (array[i][j+1] == '#') {
return;
}
if (array[i][j+1] == '*') {
array[i][j+1] = '%';
array[i][j] = '.';
}
if (array[i][j+2] == '*'&& array[i][j+1] == 'O') {
array[i][j+2] = '$';
array[i][j+1] = '@';
array[i][j] = '.';
}
if (array[i][j+1] == 'O') {
if (array[i][j+2] != '#' && array[i][j+2] != 'O') {
array[i][j+2] = 'O';
array[i][j+1] = '@';
array[i][j] = '.';
} else {
return;
}
}
if (array[i][j+1] == '$') {
array[i][j+2] = 'O';
array[i][j+1] = '%';
array[i][j] = '.';
}
if (array[i][j+1] == '.') {
array[i][j+1] = '@';
array[i][j] = '.';
}
}
if (direction == LEFT) {
if (array[i][j-1] == '#') {
return;
}
if (array[i][j-2] == '*'&& array[i][j-1] == 'O') {
array[i][j-2] = '$';
array[i][j-1] = '@';
array[i][j] = '.';
}
if (array[i][j-1] == 'O') {
if (array[i][j-2] != '#' && array[i][j-2] != 'O') {
array[i][j-2] = 'O';
array[i][j-1] = '@';
array[i][j] = '.';
} else {
return;
}
}
if (array[i][j-1] == '*') {
array[i][j-1] = '%';
array[i][j] = '.';
}
if (array[i][j-1] == '$') {
array[i][j-2] = 'O';
array[i][j-1] = '%';
array[i][j] = '.';
}
if (array[i][j-1] == '.') {
array[i][j-1] = '@';
array[i][j] = '.';
}
}
return;
}
}
}
}
void Sokoban::createMap() {
for(unsigned int i = 0; i < array.size(); i++) {
for(unsigned int j = 0; j < array[i].size(); j++) {
// builds the map to ensure that we read it in correctly
std::cout << array[i][j];
}
std::cout << std::endl;
}
}
std::istream & operator>> (std::istream& is, Sokoban& sokoban) {
std::string line;
is >> sokoban.width;
is >> sokoban.height;  // read in the dimensions
std::getline(is, line);  // skip over the new line
while(std::getline(is, line)) {
std::vector<char>row;
for(char &c : line) {
    if (c != '\n') {
row.push_back(c);
    }
}
sokoban.array.push_back(row);
}
std::copy(sokoban.array.begin(),
sokoban.array.end(), back_inserter(sokoban.originalMap));
return is;
}
int Sokoban :: getHeight() {
    return height;
}
int Sokoban :: getWidth() {
    return width;
}
void Sokoban::restartLevel() {
    array.clear();
    array = originalMap;
}
void Sokoban::draw(sf::RenderTarget& target,
sf::RenderStates states) const {
player_sprite.setTexture(player);
box_sprite.setTexture(box);
for(unsigned int i = 0; i < array.size(); i++) {
for(unsigned int j = 0; j < array[i].size(); j++) {
    if (array[i][j] == '#') {
        background_sprite.setTexture(wall);
        background_sprite.setPosition(j*64, i*64);
        target.draw(background_sprite);
    }
    if (array[i][j] == '.') {
        background_sprite.setTexture(ground);
        background_sprite.setPosition(j*64, i*64);
        target.draw(background_sprite);
    }
    if (array[i][j] == '%') {
    background_sprite.setTexture(goal);
    background_sprite.setPosition(j*64, i*64);
    player_sprite.setPosition(j*64, i*64);
    target.draw(background_sprite);
    target.draw(player_sprite);
    }
    if (array[i][j] == '$') {
    box_sprite.setPosition(j*64, i*64);
    target.draw(box_sprite);
    }
    if (array[i][j] == '*') {
        background_sprite.setTexture(goal);
        background_sprite.setPosition(j*64, i*64);
        target.draw(background_sprite);
    }
    if (array[i][j] == '@') {
        background_sprite.setTexture(ground);
        background_sprite.setPosition(j*64, i*64);
        player_sprite.setPosition(j*64, i*64);
        target.draw(background_sprite);
        target.draw(player_sprite);
    }
     if (array[i][j] == 'O') {
        background_sprite.setTexture(ground);
        background_sprite.setPosition(j*64, i*64);
        box_sprite.setPosition(j*64, i*64);
        target.draw(background_sprite);
        target.draw(box_sprite);
     }
}
}
if (isWon() == true) {
    sf::Font font;
    if (!font.loadFromFile("Jackpot.ttf")) {
std::cout << "Error loading font file" << std::endl;
    }

sf::Text text;
text.setFont(font);
text.setCharacterSize(20);
text.setString("You Win! Press R To Restart");
target.draw(text);
}
}
