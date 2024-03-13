#ifndef SOLUTIONWRAPPER_H
#define SOLUTIONWRAPPER_H

#include "stlincludes.h"

using namespace std;

#ifdef EXPECTED
#include "solution_expected.cpp"
#else
#include "solution.cpp"
#endif

#endif // SOLUTIONWRAPPER_H