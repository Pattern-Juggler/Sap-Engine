#include "Spaceship.h"
#include "HtKeyboard.h"
#include <iostream>
#include <algorithm>

void Spaceship::Initialise(Vector2D startPosition)
{
	m_position = startPosition;
	m_active = true;
	m_scale = 1;

	m_maxSpeed = 100;
	m_maxAcceleration = 10;
	m_AngleAdjustSpeed = 200;
	m_speed = 800;
	m_input.set(0, 0);
	m_desiredVelocity.set(0, 0);
	m_velocity.set(0, 0);
	LoadImage("assets/ship.bmp");
}

void Spaceship::Update(double frametime)
{
	SetDesiredVelocity();

	if (m_input.magnitude() > 0)
	{
		AdjustAngle(frametime);
	}

	AdjustVelocity(frametime);

	m_position += m_velocity * frametime;
	Render();
}

void Spaceship::SetDesiredVelocity ()
{
	m_input.set(0, 0);

	if (HtKeyboard::instance.KeyPressed(SDL_SCANCODE_W))
	{
		m_input.YValue += 1;
	}
	if (HtKeyboard::instance.KeyPressed(SDL_SCANCODE_A))
	{
		m_input.XValue -= 1;
	}
	if (HtKeyboard::instance.KeyPressed(SDL_SCANCODE_S))
	{
		m_input.YValue -= 1;
	}
	if (HtKeyboard::instance.KeyPressed(SDL_SCANCODE_D))
	{
		m_input.XValue += 1;
	}

	m_desiredVelocity.set(m_input * m_maxSpeed);
}

void Spaceship::AdjustVelocity(double frametime)
{
	Vector2D acceleration;
	acceleration.setBearing(m_angle, m_input.magnitude());
	m_velocity += acceleration * m_speed * frametime;
	m_velocity -= m_velocity * frametime;
}

void Spaceship::AdjustAngle(double frametime)
{
	double desiredAngle = m_desiredVelocity.angle();
	double angleDifference = Vector2D::AngleDifference(m_angle, desiredAngle);

	if (angleDifference > 0)
	{
		m_angle += m_AngleAdjustSpeed * frametime;
	}
	else
	{
		m_angle -= m_AngleAdjustSpeed * frametime;
	}

	//m_angle += angleDifference * m_AngleAdjustSpeed * frametime;
	//m_angle = std::max(m_angle - (m_AngleAdjustSpeed * frametime), std::min(m_angle + (m_AngleAdjustSpeed * frametime), desiredAngle));

	
}