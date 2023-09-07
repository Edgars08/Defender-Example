#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "StateMachine.h"
#include "InputManager.h"
#include "Game.h"
namespace Edgars
{

    class SpaceShip
    {
    public:
        SpaceShip(GameDataRef data);
        ~SpaceShip(){};
        void initShip();                
        void update(float dt);     
        void checkWindowCollision();      
        sf::Vector2f getPosition() const;
        sf::FloatRect getBounds() const;  
        void draw();               

    private:
        GameDataRef _data;
        sf::Sprite _ship;
        int _mDirection;
    };
}
#endif