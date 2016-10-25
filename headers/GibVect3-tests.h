#pragma once

#include <iostream>
#include <GibVect3.h>

void GibVect3Setup(const float testX, const float testY, const float testZ);
void GibVect3Add(GibVect3* testGibVect, const GibVect3* const distance, const float testX, const float testY, const float testZ);
void GibVect3IsEqual();
void GibVect3Tests();
