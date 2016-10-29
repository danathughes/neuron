#pragma once

#include <vector>

class GibVect3
{
public:
	GibVect3();
	GibVect3(const GibVect3* const vect);
	GibVect3(const std::vector<float>* const vect);
	GibVect3(const float x, const float y, const float z);
	~GibVect3();
	void Add(const GibVect3* const distance);
	bool isEqual(const GibVect3* const vect) const;
	float x() const;
	void x(const float newX);
	float y() const;
	void y(const float newY);
	float z()const;
	void z(const float newZ);

private:
	std::vector<float> elements;
};
