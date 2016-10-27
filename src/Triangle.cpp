#include <iostream>
#include <Shape.h>
#include <Triangle.h>
#include <GibVect3.h>

Triangle::Triangle(const GibVect3* const in_vert1, const GibVect3* const in_vert2, const GibVect3* const in_vert3){
	this->vert1 = new GibVect3(in_vert1);
	this->vert2 = new GibVect3(in_vert2);
	this->vert3 = new GibVect3(in_vert3);
}

Triangle::Triangle(const Triangle* const copyTriangle){
	this->vert1 = new GibVect3(copyTriangle->vert1);
	this->vert2 = new GibVect3(copyTriangle->vert2);
	this->vert3 = new GibVect3(copyTriangle->vert3);
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

float* Triangle::BufferData() const {
	float* vertices = new float[9];
	vertices[0] = vert1->x(); // TODO: Refactor; Yes, this is pathetic looking, but explicit assignment will make nasty bugs easier to find
	vertices[1] = vert1->y();
	vertices[2] = vert1->z();

	vertices[3] = vert2->x();
	vertices[4] = vert2->y();
	vertices[5] = vert2->z();

	vertices[6] = vert3->x();
	vertices[7] = vert3->y();
	vertices[8] = vert3->z();
	return vertices;
}
