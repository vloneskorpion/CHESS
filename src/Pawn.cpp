//
// Created by vlone on 28.08.22.
//

#include "Pawn.hpp"

Pawn::Pawn(float tileWidth, float tileHeight, sf::Texture &pawnsSheet)
: pawnsSheet(pawnsSheet), tileWidth(tileWidth), tileHeight(tileHeight)
{
    setPawnByTypeAndColor();
}

Pawn::~Pawn()
{

}

void Pawn::setTexture(sf::Texture &texture)
{
    sprite.setTexture(texture, true);
}

void Pawn::setPawnFromTexture(int x, int y)
{
    //Set Texture
    sf::IntRect textureRect = sf::IntRect(int(sheetOffsetX + x * textWidth), int(sheetOffsetY + y * textHeight),
                                          textWidth, textHeight);
    sprite.setTexture(pawnsSheet);
    sprite.setTextureRect(textureRect);

    //Scale
    auto scale_x = tileWidth / textureRect.width;
    auto scale_y = tileHeight / textureRect.height;
    sprite.scale(scale_x, scale_y);
}

void Pawn::setPawnByTypeAndColor()
{
    switch (static_cast<int>(pawnType))
    {
        case 0: static_cast<int>(pawnColor) == static_cast<int>(PawnColor::White) ? setPawnFromTexture(0,0) : setPawnFromTexture(0, 1); break;
        case 1: static_cast<int>(pawnColor) == static_cast<int>(PawnColor::White) ? setPawnFromTexture(1,0) : setPawnFromTexture(1, 1); break;
        case 2: static_cast<int>(pawnColor) == static_cast<int>(PawnColor::White) ? setPawnFromTexture(2,0) : setPawnFromTexture(2, 1); break;
        case 3: static_cast<int>(pawnColor) == static_cast<int>(PawnColor::White) ? setPawnFromTexture(3,0) : setPawnFromTexture(3, 1); break;
        case 4: static_cast<int>(pawnColor) == static_cast<int>(PawnColor::White) ? setPawnFromTexture(4,0) : setPawnFromTexture(4, 1); break;
        case 5: static_cast<int>(pawnColor) == static_cast<int>(PawnColor::White) ? setPawnFromTexture(5,0) : setPawnFromTexture(5, 1); break;
        default: std::cout << "pawnTYPE switch error\n";
    }
}
