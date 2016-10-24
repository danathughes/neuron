#include <iostream>
#include <Vect3.h>
#include <Vect3-tests.h>
#include <Triangle.h>

void TriangleSetup() {
  Vect3* vert1 = new Vect3(-0.5, -0.5, 0);
  Vect3* vert2 = new Vect3(-0.5, 0.5, 0);
  Vect3* vert3 = new Vect3(0.5, 0.5, 0);
  Triangle* testTriangle = new Triangle(vert1, vert2, vert3);
  if(testTriangle->vert1->isEqual(vert1) || testTriangle->vert2->isEqual(vert2) || testTriangle->vert3->isEqual(vert3)) {
    std::cout << "FAIL: TriangleSetup() \n";
  }
  else {
    std::cout << "PASS: TriangleSetup() \n";
  }
}

void TriangleMove() {
  Vect3* vert1 = new Vect3(-0.5, -0.5, 0);
  Vect3* vert2 = new Vect3(-0.5, 0.5, 0);
  Vect3* vert3 = new Vect3(0.5, 0.5, 0);
  Triangle* testTriangle = new Triangle(vert1, vert2, vert3);

  Vect3* distance = new Vect3(1.0, 1.0, 0);
  testTriangle->Move(*distance);

  Vect3* vert4 = new Vect3(0.5, 0.5, 0);
  Vect3* vert5 = new Vect3(0.5, 1.5, 0);
  Vect3* vert6 = new Vect3(1.5, 1.5, 0);

  if(testTriangle->vert1->isEqual(vert4) || testTriangle->vert2->isEqual(vert5) || testTriangle->vert3->isEqual(vert6)) {
    std::cout << "FAIL: TestTriangleMove() \n";
  }
  else {
    std::cout << "PASS: TriangleMove() \n";
  }
}

void TriangleTests() {
  TriangleSetup();
  TriangleMove();
}
