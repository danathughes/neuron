#pragma once

#include <iostream>
#include <GibVect3.h>

void TriangleSetup(float testX, float testY, float testZ, GibVect3* testVect);
void TriangleMove(GibVect3* testGibVect, GibVect3* distance, float testX, float testY, float testZ);
void TriangleTests();
