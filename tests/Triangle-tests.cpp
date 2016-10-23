#include <iostream>
#include <Vect3.h>
#include <Vect3-tests.h>
#include <Triangle.h>

void TriangleSetup(float testX, float testY, float testZ, Vect3* testVect)) {
  Vect3* vert1 = new Vect3(-0.5, -0.5, 0);
  Vect3* vert2 = new Vect3(-0.5, 0.5, 0);
  Vect3* vert3 = new Vect3(0.5, 0.5, 0);
  if(testVect->x != testX || testVect->y != testY || testVect->z != testZ) {
    std::cout << "FAIL: TestVect3Setup() \n";
    std::cout << testVect->x <<" != .5 \n";
    std::cout << testVect->y <<" != .4 \n";
    std::cout << testVect->z <<" != .3 \n";
  }
  else {
    std::cout << "PASS: TestVect3Setup() \n";
  }
}

void TriangleMove(Vect3* distance, Triangle* testTriangles) {
  testTriangle->Move(*distance);
  if(testVect->x != testX || testVect->y != testY || testVect->z != testZ) {
    std::cout << "FAIL: TestVect3Move() \n";
    std::cout << testVect->x <<" != .5 \n";
    std::cout << testVect->y <<" != .4 \n";
    std::cout << testVect->z <<" != .3 \n";
  }
  else {
    std::cout << "PASS: TestVect3Move() \n";
  }
}

void TriangleTests() {
  // TriangleSetup();
  Triangle* testTriangle = new Triangle(vert1, vert2, vert3);
  TriangleMove();
}
