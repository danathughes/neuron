#pragma once

#include <Shape.h>
#include <GibVect3.h>

class Triangle
{
public:
	Triangle();
	Triangle(const GibVect3* const vert1, const GibVect3* const vert2, const GibVect3* const vert3);
	~Triangle();
	void Move(const GibVect3* const distance);
	float* BufferData() const;

	GibVect3* vert1;
	GibVect3* vert2;
	GibVect3* vert3;
	bool dirty;
};
