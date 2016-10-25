#pragma once

#include <vector>

class GibVect3
{
public:
	GibVect3(); // TODO: This will literally never get moved; remove it?
	GibVect3(const std::vector<float>* vect);
	GibVect3(const GibVect3* vect);
	GibVect3(float x, float y, float z);
	~GibVect3();

	void Add(const GibVect3* const distance);
	bool isEqual(const GibVect3* const vect) const;

	float x() const;
	void x(float newX);
	float y() const;
	void y(float newY);
	float z()const ;
	void z(float newZ);

private:
	std::vector<float> elements;
};
