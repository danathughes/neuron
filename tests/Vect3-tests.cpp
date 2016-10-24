#include <iostream>
#include <Vect3.h>
#include <Vect3-tests.h>

void Vect3Setup(float testX, float testY, float testZ, Vect3* testVect) {
  if(testVect->x != testX || testVect->y != testY || testVect->z != testZ) {
    std::cout << "FAIL: Vect3Setup() \n";
    std::cout << testVect->x <<" != .5 \n";
    std::cout << testVect->y <<" != .4 \n";
    std::cout << testVect->z <<" != .3 \n";
  }
  else {
    std::cout << "PASS: Vect3Setup() \n";
  }
}

void Vect3IsEqual() {

}

void Vect3Move(Vect3* testVect, Vect3* distance, float testX, float testY, float testZ) {
  testVect->Move(*distance);
  if(testVect->x != testX || testVect->y != testY || testVect->z != testZ) {
    std::cout << "FAIL: Vect3Move() \n";
    std::cout << testVect->x <<" != .5 \n";
    std::cout << testVect->y <<" != .4 \n";
    std::cout << testVect->z <<" != .3 \n";
  }
  else {
    std::cout << "PASS: Vect3Move() \n";
  }
}

void Vect3Tests() {
  Vect3* testVect = new Vect3(.5, .4, .3);
  float testX = .5;
  float testY = .4;
  float testZ = .3;
  Vect3Setup(testX, testY, testZ, testVect);

  Vect3IsEqual();

  testVect = new Vect3(.5, .4, .3);
  Vect3* distance = new Vect3(.5, .4, .3);
  testX = 1.0;
  testY = .8;
  testZ = .6;
  Vect3Move(testVect, distance, testX, testY, testZ);
}
