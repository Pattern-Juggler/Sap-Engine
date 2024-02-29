#include "Game.h"

#include "HtKeyboard.h"
#include "HtMouse.h"
#include "HtGameController.h"

#include <iostream>

void Game::StartOfProgram()
{
    HtMouse::instance.SetPointerVisiblity(false);
    srand(time(0));
}

void Game::StartOfGame()
{
    ship.Initialise(Vector2D(0, 0));
    rock.Initialise(Vector2D(500, 500));
}

void Game::Update(double frameTime)
{
    ship.Update(frameTime);
    rock.Update(frameTime);
    HtGraphics::instance.Present();
}

void Game::OnSuspend()
{

}

void Game::OnResume()
{

}

void Game::EndOfGame()
{

}

void Game::EndOfProgram()
{
}
