#include <Vect3.h>
#include <Vect3-tests.h>
#include <Triangle-tests.h>

#include <iostream>

int main(int argc, const char** argv){
	std::cout << "Executing tests... \n";
	Vect3Tests();
	TriangleTests();
	return 0;
}
