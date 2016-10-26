#include <iostream>
#include <Shape.h>
#include <Triangle.h>
#include <GibVect3.h>

Triangle::Triangle(const GibVect3* const in_vert1, const GibVect3* const in_vert2, const GibVect3* const in_vert3){
	this->vert1 = new GibVect3(in_vert1);
	this->vert2 = new GibVect3(in_vert2);
	this->vert3 = new GibVect3(in_vert3);
}

Triangle::~Triangle(){

}

Triangle::Triangle() {

}

void Triangle::Move(const GibVect3* const distance){
//  for (int vertex = 0; vertex < 3; vertex++) {
//    this->vertices[vertex].Move(distance);
//  }
  this->vert1->Add(distance);
  this->vert2->Add(distance);
  this->vert3->Add(distance);
  this->dirty = true;
}
