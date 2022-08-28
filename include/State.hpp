#pragma once

#include "Entity.hpp"

class State
{
    protected:
        sf::RenderWindow* window;
        std::map<std::string, int>* supportedKeys;
        std::map<std::string, int>  keybinds;

        bool quit;

        //Resources
        std::vector<sf::Texture> textures;
        sf::Vector2i mousePosScreen;
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;

        std::stack<State*>& states;

    public:
        //Constructors & Destructors
        State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>& states);
        virtual ~State();

        //Getters & Setters
        const bool& getQuit() const;
        //TODO resolve quit function later
        void quitState();

        //Functions
        virtual void checkForQuit() = 0;
        virtual void endState() = 0;

        //-> Update
        virtual void updateMousePositions();
        virtual void updateInput(const float& dt) = 0;
        virtual void update(const float& dt) = 0;

        virtual void render(sf::RenderTarget* target = nullptr) = 0;
        virtual void initKeybinds() = 0;
};