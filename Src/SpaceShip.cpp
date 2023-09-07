#include "SpaceShip.h"
#include "GameState.h"
#include "Definations.h"

namespace Edgars
{
    SpaceShip::SpaceShip(GameDataRef data) : _data(data)
    {
        this->initShip();
    }

    void SpaceShip::initShip()
    {
        _data->assets.LoadTexture("Ship", GAMESTATE_SHIP);
        this->_ship = sf::Sprite(_data->assets.GetTexture("Ship"), sf::IntRect(120, 23, 45, 28));
        _ship.setPosition(_data->window.getSize().x * 0.80f, _data->window.getSize().y / 2);
        _ship.setScale(2.0f, 2.0f);
    }
    void SpaceShip::update(float dt)
    {
        float movement = SPACESHIP_SPEED * dt;

        if (_data->input.IsDirectionClicked(sf::Keyboard::Right))
        {
            _ship.move(sf::Vector2f(movement, 0)); // move to right
        }
        else if (_data->input.IsDirectionClicked(sf::Keyboard::Left))
        {
            _ship.move(sf::Vector2f(-movement, 0)); // move to left
        }
        else if (_data->input.IsDirectionClicked(sf::Keyboard::Up))
        {
            _ship.move(sf::Vector2f(0, -movement)); // move UP
        }
        else if (_data->input.IsDirectionClicked(sf::Keyboard::Down))
        {
            _ship.move(sf::Vector2f(0, movement)); // move DOWN
        }
        else
        {
            _ship.move(sf::Vector2f(0, 0)); // stop moving
        }
        this->checkWindowCollision();
    }
    void SpaceShip::checkWindowCollision()
    {
        if (_ship.getGlobalBounds().left < 0) // LEFT
        {
            _ship.setPosition(sf::Vector2f(0.0f, _ship.getGlobalBounds().top));
        }
        if (_ship.getGlobalBounds().left + _ship.getGlobalBounds().width > _data->window.getSize().x) // RIGHT
        {
            _ship.setPosition(sf::Vector2f(_data->window.getSize().x - _ship.getGlobalBounds().width, _ship.getGlobalBounds().top));
        }
        if (_ship.getGlobalBounds().top < 0) // TOP
        {
            _ship.setPosition(sf::Vector2f(_ship.getGlobalBounds().left, 0.0f));
        }
        if (_ship.getGlobalBounds().top + _ship.getGlobalBounds().height > _data->window.getSize().y) // BOTTOM
        {
            _ship.setPosition(sf::Vector2f(_ship.getGlobalBounds().left, _data->window.getSize().y - _ship.getGlobalBounds().height));
        }
    }

    sf::Vector2f SpaceShip::getPosition() const
    {
        return _ship.getPosition();
    }
    sf::FloatRect SpaceShip::getBounds() const
    {
        return _ship.getGlobalBounds();
    }
    void SpaceShip::draw()
    {
        this->_data->window.draw(this->_ship);
    }
}