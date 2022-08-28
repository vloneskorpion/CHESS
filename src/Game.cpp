#include "Game.hpp"

//Initialization
void Game::initWindow()
{
    //Create SFML window using options from window.ini file
    loadWindowIni("../config/window.ini");
    videoModes = sf::VideoMode::getFullscreenModes();

    windowSettings.antialiasingLevel = antialiasingLevel;
    if(fullscreen)
        window = new sf::RenderWindow(windowMode, windowTitle, sf::Style::Fullscreen, windowSettings);
    else
        window = new sf::RenderWindow(windowMode, windowTitle, sf::Style::Titlebar | sf::Style::Close, windowSettings);
    window->setFramerateLimit(frameLimit);
    window->setVerticalSyncEnabled(vSync);
}

void Game::loadWindowIni(const std::string& filepath)
{
    std::ifstream stream(filepath);
    
    if(stream.is_open())
    {
        std::getline(stream, windowTitle);
        stream >> windowMode.width >> windowMode.height;
        stream >> fullscreen;
        stream >> frameLimit;
        stream >> vSync;
        stream >> antialiasingLevel;
    } else {std::cout << "ERROR: window.ini not found!";}

    stream.close();
}

void Game::initKeys()
{
    loadKeysIni("../config/supported_keys.ini");
}

void Game::loadKeysIni(const std::string& filepath)
{
    std::ifstream stream(filepath);
    std::string key; 
    int value;
    
    if(stream.is_open())
    {
        while(stream >> key >> value)
        {
            supportedKeys.insert(std::make_pair(key,value));
        }
    } else {std::cout << "ERROR: window.ini not found!";}

    stream.close();
}

void Game::initStates()
{
    states.push(new MainMenuState(window, &supportedKeys, states));
}

//Constructors & Destructors
Game::Game()
{
    initWindow();
    initKeys();
    initStates();
}

Game::~Game()
{
    delete window;

    while(!states.empty())
    {
        delete states.top();
        states.pop();
    }
        
}


//Functions

void Game::endAppliaction()
{
    std::cout << "ENDING GAME!" << '\n';
}

void Game::updateDt()
{
    //Updates the dt with the time it takes to update and render one frame
    dt = dtClock.restart().asSeconds();
    // std::cout << "Time elapsed: " << dt << '\n';
    // system("clear");
}

void Game::updateSFMLEvents()
{
    while (window->pollEvent(sfEvent))
    {
        if (sfEvent.type == sf::Event::Closed)
            window->close();
    }
}

void Game::update()
{
    updateSFMLEvents();

    if(!states.empty())
    {
        states.top()->update(dt);

        if(states.top()->getQuit()) 
        {
            states.top()->endState();
            delete states.top();
            states.pop();
        }
    }
    //APPLICATION END
    else
    {
        endAppliaction();
        window->close();
    }
}

void Game::render()
{
    window->clear();

    if(!states.empty())
        states.top()->render(window);

    window->display();
}

void Game::run()
{
    while (window->isOpen())
    {
        updateDt();
        update();
        render();
    }
}
