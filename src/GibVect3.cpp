#include <iostream>
#include <GibVect3.h>
#include <vector>

GibVect3::GibVect3()
{
	this->elements = std::vector<float>();
}

GibVect3::GibVect3(const float x, const float y, const float z)
{
	this->elements = std::vector<float>(3);
	this->elements[0] = x;
	this->elements[1] = y;
	this->elements[2] = z;
}

GibVect3::GibVect3(const GibVect3* vect)
{
	this->elements = std::vector<float>(3);
	this->elements[0] = vect->elements[0];
	this->elements[1] = vect->elements[1];
	this->elements[2] = vect->elements[2];

}

GibVect3::GibVect3(const std::vector<float>* vect)
{
	this->elements = std::vector<float>(3);
	this->elements[0] = vect->at(0);
	this->elements[1] = vect->at(1);
	this->elements[2] = vect->at(2);
}

GibVect3::~GibVect3()
{

}

float GibVect3::x() const {
	return this->elements[0];
}

void GibVect3::x(float newX) {
	this->elements[0] = newX;
}

float GibVect3::y() const {
	return this->elements[1];
}

void GibVect3::y(float newY) {
	this->elements[1] = newY;
}

float GibVect3::z() const {
	return this->elements[2];
}

void GibVect3::z(float newZ) {
	this->elements[2] = newZ;
}

void GibVect3::Add(const GibVect3* const distance) {
	this->elements[0] += distance->x();
	this->elements[1] += distance->y();
	this->elements[2] += distance->z();
}

bool GibVect3::isEqual(const GibVect3* const otherVect) const {
	std::cout << "this->x(): " << this->x() << " || otherVect->x(): " << otherVect->x() << "\n";
	std::cout << "this->y(): " << this->y() << " || otherVect->y(): " << otherVect->y() << "\n";
	std::cout << "this->z(): " << this->z() << " || otherVect->z(): " << otherVect->z() << "\n";
	return (this->x() == otherVect->x()) && (this->y() == otherVect->y()) && (this->z() == otherVect->z());
}
