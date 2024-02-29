#include "Game.h"

#include "HtKeyboard.h"
#include "HtMouse.h"
#include "HtGameController.h"

#include <iostream>

void Game::StartOfProgram()
{
    HtMouse::instance.SetPointerVisiblity(false);
}

void Game::StartOfGame()
{
    shipImage = HtGraphics::instance.LoadPicture("assets/ship.bmp");
    shipPosition = { 300, 300 };

    shootSound = HtAudio::instance.LoadSound("assets/laser1.wav");
    thrustSound = HtAudio::instance.LoadSound("assets/thrustloop.wav");
}

void Game::Update(double frameTime)
{
    if (HtKeyboard::instance.NewKeyPressed(SDL_SCANCODE_SPACE))
    {
        HtAudio::instance.Play(shootSound);
	}

    if (HtKeyboard::instance.KeyPressed(SDL_SCANCODE_RIGHT))
    {
        angle += 0.02;
    }
    if (HtKeyboard::instance.KeyPressed(SDL_SCANCODE_LEFT))
    {
        angle -= 0.02;
    }

    velocity = { 0, 0 };

    if (HtKeyboard::instance.KeyPressed(SDL_SCANCODE_W))
    {
        velocity += { 0, 0.1 };
        HtAudio::instance.Play(thrustSound, false);
	}
    if (HtKeyboard::instance.KeyPressed(SDL_SCANCODE_A))
    {
        velocity += { -0.1, 0 };
    }
    if (HtKeyboard::instance.KeyPressed(SDL_SCANCODE_S))
    {
        velocity += { 0, -0.1 };
    }
    if (HtKeyboard::instance.KeyPressed(SDL_SCANCODE_D))
    {
        velocity += { 0.1, 0 };
    }
 
    shipPosition += velocity;
    HtGraphics::instance.DrawAt(shipPosition, shipImage);
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
