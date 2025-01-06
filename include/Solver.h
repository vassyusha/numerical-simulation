#pragma once
#include <iostream>
#include <cmath>
#include "Grid.h"
#include <fstream>

#define A 0.5
# define PI 3.141592653589793238462643383279502884L

class Solver{
public:
	std::vector<double> parabolic_eq_num(Grid<>& gr);
	double parabolic_eq(double x, double t, double l);
};

