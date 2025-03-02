#ifndef TIME_STEPPING_SOLVER_H
#define TIME_STEPPING_SOLVER_H

#include "grid.h"
#include "parameters.h"
#include "boundary_conditions.h"

void solve(Grid& grid, Parameters& params, BoundaryConditions& bc);

#endif