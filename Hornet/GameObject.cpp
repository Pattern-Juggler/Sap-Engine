#include "GameObject.h"

void GameObject::LoadImage(std::string filename)
{
	m_image = HtGraphics::instance.LoadPicture(filename);
}

GameObject::GameObject()
{
	m_position.set(0, 0);
	m_angle = 0;
	m_active = false;
	m_scale = 1;
	m_image = -1;
}

void GameObject::Render()
{
	if (m_active && m_image >= 0)
	{
		HtGraphics::instance.DrawAt(m_position, m_image, m_scale, m_angle);
	}
}