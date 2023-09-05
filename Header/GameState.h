#ifndef GAMESTATE_H
#define GAMESTATE_H

#pragma once

#include "StateMachine.h"
#include "InputManager.h"
#include "Game.h"


namespace Edgars
{
    class GameState : public State
    {
    public:
        GameState(GameDataRef data);
        ~GameState();
        void InitState();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;
        sf::Sprite _background;

        // Objects
    
    };
}
#endif