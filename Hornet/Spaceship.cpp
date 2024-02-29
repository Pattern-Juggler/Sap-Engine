#include "Spaceship.h"

void Spaceship::Initialise(Vector2D startPosition)
{
	m_position = startPosition;
	m_active = true;
	m_scale = 1;
	m_velocity.set(50, 50);
	LoadImage("assets/ship.bmp");
}

void Spaceship::Update(double frametime)
{
	m_position += m_velocity * frametime;
	Render();
}
