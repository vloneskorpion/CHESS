#include "GameState.hpp"

//Private Functions
void GameState::initKeybinds()
{
    loadKeybindsIni("../config/gamestate_keybinds.ini");
}

void GameState::loadKeybindsIni(const std::string& filepath)
{
    std::ifstream stream(filepath);
    std::string left_key; 
    std::string right_key;

    if(stream.is_open())
    {
        while(stream >> left_key >> right_key)
        {
            keybinds[left_key] = (*supportedKeys)[right_key];
        }
    } else {std::cout << "ERROR: window.ini not found!";}

    stream.close();
}

//Constructors & Destructors
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>& states) 
    :   State(window, supportedKeys, states)
{
    initKeybinds();
}

GameState::~GameState()
{

}

//Functions
void GameState::endState()
{
    std::cout << "ENDING GAMESTATE!" << '\n';
}

void GameState::checkForQuit()
{
    if(sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(keybinds["CLOSE"])))
        quit = true;
}

void GameState::updateInput(const float& dt)
{
    checkForQuit();
}

void GameState::update(const float& dt)
{
    updateMousePositions();
    updateInput(dt);
}

void GameState::render(sf::RenderTarget* target)
{
    if(!target)
        target = window;
}
