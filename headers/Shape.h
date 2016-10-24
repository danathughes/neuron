#pragma once

#include <Vect3.h>

class Shape
{
public:
//	Shape();
//	~Shape();
  virtual void Move(const Vect3 distance) = 0;
};
