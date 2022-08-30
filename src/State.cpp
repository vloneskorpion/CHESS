#include "State.hpp"

//Constructors & Destructors
State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>& states) 
    : window(window), quit(false), supportedKeys(supportedKeys), states(states)
{

}

State::~State()
{
    
}

//Functions

const bool& State::getQuit() const
{
    return quit;
}

void State::quitState()
{
    quit = true;
}

void State::updateMousePositions()
{
    mousePosScreen = sf::Mouse::getPosition();
    mousePosWindow = sf::Mouse::getPosition(*window);
    mousePosView   = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
}

std::unique_ptr<sf::Image> State::makeImageColorTransparent(std::string filepath, sf::Color color)
{
    std::unique_ptr<sf::Image> imgPtr = std::make_unique<sf::Image>();
    imgPtr->loadFromFile(filepath);
    imgPtr->createMaskFromColor(color);

    return imgPtr;
}