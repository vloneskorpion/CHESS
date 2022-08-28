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

void GameState::updateInput(const float& dt)
{
    checkForQuit();

    //Update player input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds["MOVE_LEFT"])))      player.move(dt, -1.0f,  0.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds["MOVE_RIGHT"])))     player.move(dt,  1.0f,  0.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds["MOVE_UP"])))        player.move(dt,  0.0f, -1.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds["MOVE_DOWN"])))      player.move(dt,  0.0f,  1.0f);
}

void GameState::update(const float& dt)
{
    updateMousePositions();
    updateInput(dt);

    player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
    if(!target)
        target = window;
    player.render(target);
}
