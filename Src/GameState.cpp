#include "GameState.h"
#include "StateMachine.h"
#include "Definations.h"
#include <sstream>

namespace Edgars
{
    GameState::GameState(GameDataRef data) : _data(data)
    {
    }
    GameState::~GameState()
    {
    }
    void GameState::InitState()
    {
        // Init background
        _data->assets.LoadTexture("Background_Game", GAMESTATE_BACKGROUND);
        this->_background.setTexture(_data->assets.GetTexture("Background_Game"));
        this->_background.setScale(sf::Vector2f(1.50f, 1.55210643f));
        // OBJECT
    }
    void GameState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                _data->window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                _data->window.close();
            }
        }
    }

    void GameState::Update(float dt)
    {
    }

    void GameState::Draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.display();
    }
}