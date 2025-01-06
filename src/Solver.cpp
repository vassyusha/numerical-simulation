#include "Solver.h"

std::vector<double> Solver::parabolic_eq_num(Grid<>& gr) {

	double maxd = 0;

	std::ofstream out;
	out.open("../../file.csv");//C:/Users/roman/source/repos/ItLab

	int t = 0;
	for (; t < K; t++) {
		maxd = 0;
		for (int i = 0; i < N; i++) {
			if (i == 0 || i == N - 1) gr[(t + 1) % 2][i] = gr[t % 2][i];
			else {
				gr[(t + 1) % 2][i] = ((A * A) / (gr.dx * gr.dx) * gr.dt) * gr[t % 2][i - 1] + (1 / gr.dt - 2 * A * A / (gr.dx * gr.dx)) * gr.dt * gr[t % 2][i] + ((A * A) / (gr.dx * gr.dx) * gr.dt) * gr[t % 2][i + 1];
			}
			std::cout << gr[(t + 1) % 2][i] << "  ";
			out << i * gr.dx << ";" << gr[(t + 1) % 2][i] << "\n";

			double u = this->parabolic_eq(i * gr.dx, t * gr.dt, gr.dx * (N - 1));
			if (maxd < abs(u - gr[(t + 1) % 2][i])) maxd = abs(u -  gr[(t + 1) % 2][i]);
		}std::cout << "  " << maxd << "\n";
		out << "\n";
	}

	out.close();

	return gr[t % 2];

}

double Solver::parabolic_eq(double x, double t, double l) {

	double u = sin(2 * PI * x / l) * exp(-A * A * (2 * PI / l) * (2 * PI / l) * t);

	return u;
}