#pragma once
#include <vector>
#include "HtAudio.h"
#include "HtGraphics.h"

class GameObject
{
protected:
	Vector2D m_position;
	bool m_active;
	double m_angle;
	double m_scale;

	void LoadImage(std::string filename);

private:
	PictureIndex m_image;

public:
	GameObject();

	virtual void Render();
	virtual void Update(double frametime) = 0;
};

