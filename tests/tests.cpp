#include <GibVect3.h>
#include <GibVect3-tests.h>
#include <Triangle-tests.h>

#include <iostream>

int main(int argc, const char** argv){
	std::cout << "Executing tests... \n";
	GibVect3Tests();
	TriangleTests();
	std::cout << "Tests complete! Press enter to quit. \n";
	getchar();
	return 0;
}