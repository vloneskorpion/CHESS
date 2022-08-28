#include "MainMenuState.hpp"

//Private Functions
void MainMenuState::initBackground()
{
    background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));

    if(!backgroundTexture.loadFromFile("../resources/images/backgrounds/background.jpg"))
        std::cout << "ERROR: COULDNT LOAD TEXTURE" << '\n';

    background.setTexture(&backgroundTexture);
}

void MainMenuState::initFonts()
{
    if(!font.loadFromFile("../fonts/Cascadia.ttf"))
    {
        throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
    }
}

void MainMenuState::initKeybinds()
{
    loadKeybindsIni("../config/mainmenustate_keybinds.ini");
}

void MainMenuState::loadKeybindsIni(const std::string& filepath)
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

void MainMenuState::initButtons()
{
    buttons["GAME_STATE"] = new Button(125, 180, 250, 70,
                                &font, "NEW GAME",
                                sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

    buttons["SETTINGS"] =   new Button(125, 280, 250, 70,
                                &font, "SETTINGS",
                                sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

    buttons["EXIT"] =      new Button(125, 380, 250, 70,
                                &font, "EXIT",
                                sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

//Constructors & Destructors
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>& states)
    :   State(window, supportedKeys, states)
{
    initBackground();
    initFonts();
    initKeybinds();
    initButtons();
}

MainMenuState::~MainMenuState()
{
    for(auto it = buttons.begin(); it != buttons.end(); ++it)
    {
        delete it->second;
    }
}

//Functions
void MainMenuState::endState()
{
    std::cout << "ENDED MAIN MENU!" << '\n';
}

void MainMenuState::updateInput(const float& dt)
{
    checkForQuit();
}

void MainMenuState::updateButtons()
{
    //Updated all buttons in the state and handles their functionality
    for(const auto& kv : buttons)
    {
        kv.second->update(mousePosView);
    }

    if(buttons["GAME_STATE"]->isPressed())
    {
        states.push(new GameState(window, supportedKeys, states));
    }

    //Quit the game
    if(buttons["EXIT"]->isPressed())
    {
        quitState();
    }
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
    for(const auto& kv : buttons)
    {
        kv.second->redner(target);
    }
}

void MainMenuState::update(const float& dt)
{
    updateMousePositions();
    updateInput(dt);

    updateButtons();

}

void MainMenuState::render(sf::RenderTarget* target)
{
    if(!target)
        target = window;
    target->draw(background);

    renderButtons(target);


    //REMOVE LATER - just for checking mouse pos
    // sf::Text mouseTex;
    // mouseTex.setPosition(mousePosView.x + 30, mousePosView.y);
    // mouseTex.setFont(font);
    // mouseTex.setCharacterSize(12);
    // std::stringstream ss;
    // ss << mousePosView.x << " " << mousePosView.y;
    // mouseTex.setString(ss.str());
    // target->draw(mouseTex);
} 
