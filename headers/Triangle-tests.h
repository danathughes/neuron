#pragma once

#include <iostream>
#include <Vect3.h>

void TriangleSetup(float testX, float testY, float testZ, Vect3* testVect);
void TriangleMove(Vect3* testVect, Vect3* distance, float testX, float testY, float testZ);
void TriangleTests();
