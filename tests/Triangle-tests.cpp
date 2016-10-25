#include <iostream>
#include <GibVect3.h>
#include <GibVect3-tests.h>
#include <Triangle.h>

void TriangleSetup() {
	GibVect3* vert1 = new GibVect3(-0.5, -0.5, 0);
	GibVect3* vert2 = new GibVect3(-0.5, 0.5, 0);
	GibVect3* vert3 = new GibVect3(0.5, 0.5, 0);
	Triangle* testTriangle = new Triangle(vert1, vert2, vert3);
	if(testTriangle->vert1->isEqual(vert1) || testTriangle->vert2->isEqual(vert2) || testTriangle->vert3->isEqual(vert3)) {
		std::cout << "FAIL: TriangleSetup() \n";
	}
	else {
		std::cout << "PASS: TriangleSetup() \n";
	}
}

void TriangleMove() {
	GibVect3* vert1 = new GibVect3(-0.5, -0.5, 0);
	GibVect3* vert2 = new GibVect3(-0.5, 0.5, 0);
	GibVect3* vert3 = new GibVect3(0.5, 0.5, 0);
	Triangle* testTriangle = new Triangle(vert1, vert2, vert3);

	GibVect3* distance = new GibVect3(1.0, 1.0, 0);
	testTriangle->Move(distance);

	GibVect3* vert4 = new GibVect3(0.5, 0.5, 0);
	GibVect3* vert5 = new GibVect3(0.5, 1.5, 0);
	GibVect3* vert6 = new GibVect3(1.5, 1.5, 0);

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
