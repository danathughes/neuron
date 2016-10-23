#pragma once

class Vect3 // TODO: Inherit from a Vector class
{
public:
	Vect3(); // TODO: This will literally never get moved; remove it?
	Vect3(float x, float y, float z);
	~Vect3();
	float x;
	float y;
	float z;
	void Move(Vect3 distance);
};
