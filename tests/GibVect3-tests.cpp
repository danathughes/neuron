#include <iostream>
#include <GibVect3.h>
#include <GibVect3-tests.h>

void GibVect3Setup(const float testX, const float testY, const float testZ) {
	GibVect3* testVect = new GibVect3(testX, testY, testZ);
	if(testVect->x() != testX || testVect->y() != testY || testVect->z() != testZ) {
		std::cout << "FAIL: Vect3Setup() \n";
		std::cout << testVect->x() <<" != .5 \n";
		std::cout << testVect->y() <<" != .4 \n";
		std::cout << testVect->z() <<" != .3 \n";
	}
    else {
		std::cout << "PASS: Vect3Setup() \n";
	}
}

void GibVect3IsEqual() {

}

void GibVect3Add(GibVect3* testGibVect, const GibVect3* const distance, float testX, float testY, float testZ) {
  testGibVect->Add(distance);
  if (testGibVect->x() != testX || testGibVect->y() != testY || testGibVect->z() != testZ) {
    std::cout << "FAIL: Vect3Move() \n";
	std::cout << testGibVect->x() << " != .5 \n";
	std::cout << testGibVect->y() << " != .4 \n";
	std::cout << testGibVect->z() << " != .3 \n";
  }
  else {
    std::cout << "PASS: Vect3Move() \n";
  }
}

void GibVect3Tests() {
	GibVect3* testGibVect = new GibVect3(.5, .4, .3);
	float testX = .5;
	float testY = .4;
	float testZ = .3;
	GibVect3Setup(testX, testY, testZ);

	GibVect3IsEqual();

	testGibVect = new GibVect3(.5, .4, .3);
	GibVect3* distance = new GibVect3(.5, .4, .3);
	testX = 1.0;
	testY = .8;
	testZ = .6;
	GibVect3Add(testGibVect, distance, testX, testY, testZ);
}
