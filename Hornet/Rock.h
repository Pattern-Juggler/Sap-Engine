#pragma 
#include "GameObject.h"

class Rock : public GameObject
{
public:
	void Initialise(Vector2D startPosition);
	void Update(double frametime) override;

};

