#include <iostream>
#include <GibVect3.h>
#include <GibVect3-tests.h>
#include <Triangle.h>

void TriangleSetup() {
	GibVect3* vert1 = new GibVect3(-0.5, -0.5, 0);
	GibVect3* vert2 = new GibVect3(-0.5, 0.5, 0);
	GibVect3* vert3 = new GibVect3(0.5, 0.5, 0);
	Triangle* testTriangle = new Triangle(vert1, vert2, vert3);
	if(testTriangle->vert1->isEqual(vert1) && testTriangle->vert2->isEqual(vert2) && testTriangle->vert3->isEqual(vert3)) {
		std::cout << "PASS: TriangleSetup() \n";
	}
	else {
		std::cout << "FAIL: TriangleSetup() \n";
	}
}

void TriangleMove() {
	// Make the triangle
	GibVect3* vert1 = new GibVect3(-0.5, -0.5, 0);
	GibVect3* vert2 = new GibVect3(-0.5, 0.5, 0);
	GibVect3* vert3 = new GibVect3(0.5, 0.5, 0);
	Triangle* testTriangle = new Triangle(vert1, vert2, vert3);

	// Move it (each vert) a certain distance
	GibVect3* distance = new GibVect3(1.0, 1.0, 0);
	testTriangle->Move(distance);

	// Then calculate how much each vert SHOULD have moved, and compare it to that
	GibVect3* vert4 = new GibVect3(0.5, 0.5, 0);
	GibVect3* vert5 = new GibVect3(0.5, 1.5, 0);
	GibVect3* vert6 = new GibVect3(1.5, 1.5, 0);

	if(testTriangle->vert1->isEqual(vert4) && testTriangle->vert2->isEqual(vert5) && testTriangle->vert3->isEqual(vert6)) {
		std::cout << "PASS: TriangleMove() \n";
	}
	else {
		std::cout << "FAIL: TestTriangleMove() \n";
	}
}

void TriangleTests() {
  TriangleSetup();
  TriangleMove();
}
