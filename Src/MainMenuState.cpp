#include "MainMenuState.h"
#include "GameState.h"
#include <sstream>
#include <iostream>
#include "Definations.h"

namespace Edgars
{
    MainMenuState::MainMenuState(GameDataRef data) : _data(data)
    {
    }

    void MainMenuState::InitState()
    {
        // stored in a map
        this->_data->assets.LoadTexture("Background_space", MAINMENU_BACKGROUND);
        this->_background.setTexture(_data->assets.GetTexture("Background_space"));
        _background.setScale(sf::Vector2f(0.9523809524f, 1.178451178f));

        this->InitText();
    }

    void MainMenuState::InitText()
    {
        // load font
        this->_data->assets.LoadFont("Font", MAINMENU_FONT);
        // load text
        this->play_text.setFont(_data->assets.GetFont("Font"));
        this->play_text.setCharacterSize(40);
        this->play_text.setFillColor(sf::Color::White);

        this->quit_text = this->play_text;
        this->play_text.setString("Play");
        this->quit_text.setString("Quit");

        this->title = this->play_text;
        this->title.setString("DEFENDER");
        this->title.setFillColor(sf::Color::Red);
        this->title.setCharacterSize(60);

        this->play_text.setPosition((SCREEN_WIDTH - play_text.getGlobalBounds().width) / 2, (SCREEN_HEIGHT - play_text.getGlobalBounds().height) / 2);
        this->quit_text.setPosition((SCREEN_WIDTH - quit_text.getGlobalBounds().width) / 2, SCREEN_HEIGHT / 2 + play_text.getGlobalBounds().height * 2.0f);
        this->title.setPosition((SCREEN_WIDTH - title.getGlobalBounds().width) / 2, (SCREEN_HEIGHT - title.getGlobalBounds().height * 6.0f) / 2);
    }

    void MainMenuState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type || _data->input.IsClicked(this->quit_text, sf::Mouse::Left, _data->window))
            {
                _data->window.close();
            }
            if (_data->input.IsClicked(this->play_text, sf::Mouse::Left, _data->window))
            {
                _data->machine.AddState(StateRef(new GameState(_data)), true);
            }
            if (_data->input.IsHovering(this->quit_text, _data->window))
            {
                this->quit_text.setFillColor(sf::Color::Green);
            }
            else
            {
                this->quit_text.setFillColor(sf::Color::White);
            }
            if (_data->input.IsHovering(this->play_text, _data->window))
            {
                this->play_text.setFillColor(sf::Color::Green);
            }
            else
            {
                this->play_text.setFillColor(sf::Color::White);
            }
        }
    }

    void MainMenuState::Update(float dt)
    {
    }
    void MainMenuState::Draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.draw(play_text);
        _data->window.draw(quit_text);
        _data->window.draw(title);
        _data->window.display();
    }
}