#include <iostream>
#include <Vect3.h>
#include <Vect3-tests.h>

void TestVect3Setup() {
  Vect3* testVect = new Vect3(.5, .4, .3);
  float testX = .5;
  float testY = .4;
  float testZ = .3;
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

void TestVect3Move() {
  Vect3* testVect = new Vect3(.5, .4, .3);
  Vect3* distance = new Vect3(.5, .4, .3);
  float testX = 1.0;
  float testY = .8;
  float testZ = .6;
  testVect->Move(*distance);
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

void Vect3Tests() {
  TestVect3Setup();
  TestVect3Move();
}
