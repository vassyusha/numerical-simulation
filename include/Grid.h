#pragma once
#include <vector>

#define N 50
#define K 20

template<class T = double>
class Grid{
private:
	std::vector<std::vector<T>> grid; //сделать два вектора вместо 1 двумерного
	
public:
	const double dt;
	const double dx;

	Grid(const std::vector<T> data, double dt, double dx) :grid(std::vector<std::vector<T>>(2, data)), dt(dt), dx(dx) {}

	std::vector<T>& operator[](std::size_t i) { return this->grid[i]; }

};

