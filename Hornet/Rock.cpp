#include "Rock.h"

void Rock::Initialise(Vector2D startPosition)
{
	m_position = startPosition;
	m_active = true;
	m_scale = 1;

	int number = rand() % 4;
	switch (number)
	{
	case 0:
		LoadImage("assets/rock1.bmp");
		break;

	case 1:
		LoadImage("assets/rock2.bmp");
		break;

	case 2:
		LoadImage("assets/rock3.bmp");
		break;

	case 3:
		LoadImage("assets/rock4.bmp");
		break;
	}
}

void Rock::Update(double frametime)
{
	Render();
}