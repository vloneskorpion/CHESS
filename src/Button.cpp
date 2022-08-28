#include "Button.hpp"

Button::Button(float x, float y, float width, float height,
               sf::Font* font, std::string text_button, unsigned character_size,
               sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
               sf::Color idle_color, sf::Color hover_color, sf::Color active_color)
{
    buttonState = BTN_IDLE;

    shape.setPosition(sf::Vector2f(x,y));
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(idle_color);

    font = font;
    text.setFont(*font);
    text.setString(text_button);
    text.setFillColor(text_idle_color);
    text.setCharacterSize(character_size);
    text.setPosition(
            shape.getPosition().x + shape.getGlobalBounds().width / 2.0f    - text.getGlobalBounds().width / 2.0f,
            shape.getPosition().y + shape.getGlobalBounds().height / 2.0f   - text.getGlobalBounds().height / 2.0f
    );

    textIdleColor   = text_idle_color;
    textHoverColor  = text_hover_color;
    textActiveColor = text_active_color;

    idleColor   = idle_color;
    hoverColor  = hover_color;
    activeColor = active_color;
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
            text.setFillColor(textIdleColor);
            break;
        case BTN_HOVER:
            shape.setFillColor(hoverColor);
            text.setFillColor(textHoverColor);
            break;
        case BTN_ACTIVE:
            shape.setFillColor(activeColor);
            text.setFillColor(textActiveColor);
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