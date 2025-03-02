#include "grid.h"
#include "parameters.h"
#include "boundary_conditions.h"
#include "time_stepping_solver.h"
#include <iostream>

void solve(Grid& grid, Parameters& params, BoundaryConditions& bc) {
    double coef = (params.c * params.dt / grid.dx) * (params.c * params.dt / grid.dx);
    for (int n = 0; n < params.steps; n++) {
        for (int i = 1; i < grid.nx - 1; i++) {
            grid.u_next[i] = 2 * grid.u[i] - grid.u_prev[i] + coef * (grid.u[i+1] - 2 * grid.u[i] + grid.u[i-1]);
        }
        bc.apply(grid.u_next);
        grid.u_prev = grid.u;
        grid.u = grid.u_next;
    }
}
