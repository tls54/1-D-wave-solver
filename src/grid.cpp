#include "grid.h"

Grid::Grid(int nx, double dx) : nx(nx), dx(dx), u(nx, 0.0), u_prev(nx, 0.0), u_next(nx, 0.0) {}



void Grid::initialize(std::function<double(double)> init_func) {
    for (int i = 0; i < nx; i++) {
        double x = i * dx;
        u[i] = init_func(x);
    }
    u_prev = u;
}