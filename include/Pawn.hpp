//
// Created by vlone on 28.08.22.
//

#ifndef GAME_PAWN_H
#define GAME_PAWN_H

#include "Entity.hpp"

enum class PawnType
{
    Pawn,
    Bishop,
    Knight,
    Rook,
    Queen,
    King
};

enum class PawnColor
{
    White,
    Black
};

class Pawn : public Entity
{
private:
    sf::Texture& pawnsSheet;
    PawnType pawnType = PawnType::Pawn;
    PawnColor pawnColor = PawnColor::White;

    //Board
    float tileWidth;
    float tileHeight;

    //Texture Sheet
    int textWidth = 300;
    int textHeight = 365;
    float sheetOffsetX = 100.0f;
    float sheetOffsetY = 100.0f;

public:
    //Constructors & Destructors
    Pawn(float tileWidth, float tileHeight, sf::Texture &pawnsSheet);
    ~Pawn();

    //Functions
    void setTexture(sf::Texture& texture);
    void setPawnFromTexture(int x, int y);
    void setPawnByTypeAndColor();
};


#endif //GAME_PAWN_H
