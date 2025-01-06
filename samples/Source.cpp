
#include <iostream>
#include "Solver.h"


int main() {

	double dt, dx;
	std::cin >> dt >> dx;
	std::vector<double> data(N);

	double l = dx * (N-1);
	Solver sl;

	for (int i = 0; i < N-1; i++) {
		data[i] = sl.parabolic_eq(i * dx, 0, l);
		std::cout << data[i] << " ";
	}
	data[N - 1] = 0;
	std::cout << data[N-1]<< "\n";

	int t = 1;
	for (; t < K; t++) {
		for (int i = 0; i < N; i++) {
			double u = sl.parabolic_eq(i * dx, t * dt, l);
			std::cout << u << " ";
		}std::cout << "\n";
	}

	std::cout << "\n\n";

	Grid<> gr(data, dt, dx);

	sl.parabolic_eq_num(gr);

	return 0;
}