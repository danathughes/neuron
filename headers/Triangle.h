#pragma once

#include <Shape.h>
#include <Vect3.h>

class Triangle : Shape
{
public:
	Triangle();
	Triangle(const Vect3* vert1, const Vect3* vert2, const Vect3* vert3);
	~Triangle();
  void Move(const Vect3 distance);
	Vect3* vert1;
	Vect3* vert2;
	Vect3* vert3;
	//Vect3 vertices[3]; // TODO: Figure out what "explicitly virtualize"ing this looks like and make it a private array
};
