//
// Created by vlone on 28.08.22.
//

#include "Board.hpp"

Board::Board(std::map<std::string ,sf::Texture>* textures, float width, float height)
    : textures(textures)
{
    tileWidth = width / ROW;
    tileHeight = height / COL;
    createBoard();
    pawn = new Pawn(tileWidth, tileHeight, (*textures)["PAWNS_SHEET"]);
}

Board::~Board()
{
    delete pawn;
}

void Board::createSizeAndColor()
{
    for(int i = 1; i <= ROW; i++)
    {
        for(int j = 1; j <= COL; j++)
        {
            shapes[i-1][j-1].setSize(sf::Vector2f(tileWidth, tileHeight));
            if(j % 2 != 0)
            {
                if(i % 2 != 0) {shapes[i-1][j-1].setFillColor(blueTile);}
                else {shapes[i-1][j-1].setFillColor(whiteTile);}
            }
            else
            {
                if(i % 2 != 0) {shapes[i-1][j-1].setFillColor(whiteTile);}
                else {shapes[i-1][j-1].setFillColor(blueTile);}
            }
        }
    }
}

void Board::positionTiles()
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            shapes[i][j].setPosition(i * tileWidth, j * tileHeight);
        }
    }
}

void Board::createBoard()
{
    createSizeAndColor();
    positionTiles();
}

void Board::update(const float &dt)
{
    pawn->update(dt);
}

void Board::render(sf::RenderTarget *target)
{
    //Render board
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            target->draw(shapes[i][j]);
        }
    }
    //Render pawns
    pawn->render(target);
}
