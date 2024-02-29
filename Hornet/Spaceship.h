#pragma once
#include <vector>
#include "HtGraphics.h"
#include "GameObject.h"
class Spaceship : public GameObject
{
private:
	Vector2D m_velocity;

public:
	void Initialise(Vector2D startPosition);
	void Update(double frametime) override;
};

