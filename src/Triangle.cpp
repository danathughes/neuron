#include <iostream>
#include <Shape.h>
#include <Triangle.h>

Triangle::Triangle(const Vect3 in_vert1, const Vect3 in_vert2, const Vect3 in_vert3){
  this->vert1 = in_vert1;
  this->vert2 = in_vert2;
  this->vert3 = in_vert3;
}

Triangle::~Triangle(){

}

void Triangle::Move(const Vect3 distance){
//  for (int vertex = 0; vertex < 3; vertex++) {
//    this->vertices[vertex].Move(distance);
//  }
  this->vert1.Move(distance);
  this->vert2.Move(distance);
  this->vert3.Move(distance);
}
