#pragma once

#include <GibVect3.h>

class Shape
{
public:
//	Shape();
//	~Shape();
	virtual void Move(const GibVect3 distance) = 0;
};
