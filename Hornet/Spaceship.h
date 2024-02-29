#pragma once
#include <vector>
#include "HtGraphics.h"
#include "GameObject.h"
class Spaceship : public GameObject
{
private:
	double m_maxSpeed;
	double m_maxAcceleration;
	double m_AngleAdjustSpeed;
	double m_speed;
	Vector2D m_input;
	Vector2D m_desiredVelocity;
	Vector2D m_velocity;

public:
	void Initialise(Vector2D startPosition);
	void Update(double frametime) override;
	void SetDesiredVelocity();
	void AdjustVelocity(double frametime);
	void AdjustAngle(double frametime);
};

