#include "SplashState.h"
#include "MainMenuState.h"
#include <iostream>
#include "Definations.h"
namespace Edgars
{
    SplashState::SplashState(GameDataRef data) : _data(data)
    {
    }

    void SplashState::InitState()
    {
        // store them in a map ...then get
        _data->assets.LoadTexture("splashbackground", SPLASHSTATE_BACKGROUND);
        _background.setTexture(_data->assets.GetTexture("splashbackground"));
        _background.setScale(sf::Vector2f(1.0f, 0.7777778f));

        this->_clock.restart();
    }

    void SplashState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                _data->window.close();
            }
        }
    }
    void SplashState::Update(float dt)
    {
        if (_clock.getElapsedTime().asSeconds() > SPLASHSTATE_SHOW_TIME)
        {
            _data->machine.AddState(StateRef(new MainMenuState(_data)), true); // on stack
        }
    }
    void SplashState::Draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.display();
    }

}
