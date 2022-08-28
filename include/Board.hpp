//
// Created by vlone on 28.08.22.
//

#ifndef GAME_BOARD_HPP
#define GAME_BOARD_HPP

//Standard libs
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

//SFML
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum class Pawns
{
    Pawn,
    Bishop,
    Knight,
    Rook,
    Queen,
    King
};

class Board
{
private:
    sf::Sprite sprite;

    //Initialization board variables
    static constexpr int ROW = 8;
    static constexpr int COL = 8;
    sf::RectangleShape shapes[ROW][COL];
    sf::Color blueTile = sf::Color::Blue;
    sf::Color whiteTile = sf::Color::White;

    float tileWidth;
    float tileHeight;
    Pawns boardArray[8][8];


public:

    //Constructors & Destructors
    Board(float width, float height);
    ~Board();

    //Initialization
    void createSizeAndColor();
    void positionTiles();
    void createBoard();

    //Functions
    void update(const float& dt);
    void render(sf::RenderTarget* target);
};


#endif //GAME_BOARD_HPP
