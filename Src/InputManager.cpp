#include "InputManager.h"

namespace Edgars
{
    InputManager::InputManager()
    {
    
    }

    bool InputManager::IsDirectionClicked(sf::Keyboard::Key button)
    {
        if (sf::Keyboard::isKeyPressed(button))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
 
    bool InputManager::IsClicked(sf::Text text, sf::Mouse::Button button, sf::RenderWindow &window)
    {
        if (sf::Mouse::isButtonPressed(button))
        {
            sf::IntRect tempRect(text.getPosition().x,text.getPosition().y, text.getGlobalBounds().width, text.getGlobalBounds().height);
            if (tempRect.contains(sf::Mouse::getPosition(window))) 
            {
                return true;
            }
        }
        return false;
    }
    bool InputManager::IsHovering(sf::Text text, sf::RenderWindow &window)
    {
        sf::IntRect tempRect(text.getPosition().x, text.getPosition().y, text.getGlobalBounds().width, text.getGlobalBounds().height);
        if (tempRect.contains(sf::Mouse::getPosition(window)))
        {
            return true;
        }
        return false;
    }
    sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window)
    {
        return sf::Mouse::getPosition(window);
    }

 
}
