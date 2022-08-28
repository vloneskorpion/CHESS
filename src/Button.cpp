#include "Button.hpp"

Button::Button(float x, float y, float width, float height,
sf::Font* font, std::string text_button,
sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
    buttonState = BTN_IDLE;

    shape.setPosition(sf::Vector2f(x,y));
    shape.setSize(sf::Vector2f(width, height));
    
    font = font;
    text.setFont(*font);
    text.setString(text_button);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(20);
    text.setPosition(
        shape.getPosition().x + shape.getGlobalBounds().width / 2.0f    - text.getGlobalBounds().width / 2.0f,
        shape.getPosition().y + shape.getGlobalBounds().height / 2.0f   - text.getGlobalBounds().height / 2.0f
    );

    idleColor = idleColor;
    hoverColor = hoverColor;
    activeColor = activeColor;

    shape.setFillColor(idleColor);
}

Button::~Button()
{
    
}

const bool Button::isPressed() const
{
    if(buttonState == BTN_ACTIVE)
        return true;
    return false;
}

void Button::redner(sf::RenderTarget* target)
{
    target->draw(shape);
    target->draw(text);
}

void Button::switchState()
{
    switch (buttonState)
    {
    case BTN_IDLE:
        shape.setFillColor(idleColor);
        break;
    case BTN_HOVER:
        shape.setFillColor(hoverColor);
        break;
    case BTN_ACTIVE:
        shape.setFillColor(activeColor);
        break;
    default:
        shape.setFillColor(sf::Color::Red); //for checking purposes, it should not happen
        break;
    }
}

void Button::update(const sf::Vector2f mousePos)
{
    //Update the boolens for hover and pressed
    
    //Idle
    buttonState = BTN_IDLE;

    //Hover
    if(shape.getGlobalBounds().contains(mousePos))
    {
        buttonState = BTN_HOVER;

        //Pressed
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            buttonState = BTN_ACTIVE;
        }
    }

    switchState();
}