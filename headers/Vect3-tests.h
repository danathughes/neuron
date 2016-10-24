#pragma once

#include <iostream>
#include <Vect3.h>

void Vect3Setup(float testX, float testY, float testZ, Vect3* testVect);
void Vect3Move(Vect3* testVect, Vect3* distance, float testX, float testY, float testZ);
void Vect3IsEqual();
void Vect3Tests();
