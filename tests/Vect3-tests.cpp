#include <iostream>
#include <Vect3.h>
#include <Vect3-tests.h>

void TestVect3Setup(float testX, float testY, float testZ, Vect3* testVect) {
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

void TestVect3Move(Vect3* testVect, Vect3* distance, float testX, float testY, float testZ) {
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
  Vect3* testVect = new Vect3(.5, .4, .3);
  float testX = .5;
  float testY = .4;
  float testZ = .3;
  TestVect3Setup(testX, testY, testZ, testVect);

  testVect = new Vect3(.5, .4, .3);
  Vect3* distance = new Vect3(.5, .4, .3);
  testX = 1.0;
  testY = .8;
  testZ = .6;
  TestVect3Move(testVect, distance, testX, testY, testZ);
}
