#include <iostream>
#include <Vect3.h>

Vect3::Vect3(float x, float y, float z)
{
  this->x = x;
  this->y = y;
  this->z = z;
}

Vect3::Vect3()
{

}

Vect3::~Vect3()
{

}

void Vect3::Move(Vect3 distance){
  this->x += distance.x;
  this->y += distance.y;
  this->z += distance.z;
}
