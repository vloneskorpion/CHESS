#pragma once

#include "MainMenuState.hpp"

class Game
{
    private:
        //VARIABLES
        sf::RenderWindow* window;
        sf::Event sfEvent;
        std::vector<sf::VideoMode> videoModes; 

        //-> Window options
        std::string windowTitle{"None"};
        sf::VideoMode windowMode{sf::VideoMode::getDesktopMode()};
        sf::ContextSettings windowSettings;
        bool fullscreen{false};
        unsigned int frameLimit{120};
        bool vSync{false};
        unsigned antialiasingLevel{0};


        //-> Time options
        sf::Clock dtClock;
        float dt;

        //-> Game states
        std::stack<State*> states;

        //-> Core
        std::map<std::string, int> supportedKeys;

        //Initialization
        void initWindow();
        void loadWindowIni(const std::string& filepath);
        void initKeys();
        void loadKeysIni(const std::string& filepath);
        void initStates();

    public:
        //Constructors & Destructors
        Game();
        virtual ~Game();

        //Functions

        //-> Regular
        void endAppliaction();

        //-> Update
        void updateDt();
        void updateSFMLEvents();
        void update();
        
        //-> Render
        void render();

        //-> Core
        void run();
};