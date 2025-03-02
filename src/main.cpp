#include "grid.h"
#include "parameters.h"
#include "boundary_conditions.h"
#include "time_stepping_solver.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <c_squared> <boundary_type> <initial_type>\n";
        return 1;
    }
    
    double c_squared = std::atof(argv[1]);
    std::string boundary_type = argv[2];
    std::string initial_type = argv[3];
    
    int nx = 100;
    double dx = 1.0 / (nx - 1);
    double CFL = 0.5, t_max = 2.0;
    
    Grid grid(nx, dx);
    grid.initialize([&](double x) { return createInitialCondition(initial_type, x); });
    
    Parameters params(c_squared, dx, CFL, t_max);
    
    BoundaryConditions* bc = createBoundaryCondition(boundary_type);
    if (!bc) return 1;
    
    solve(grid, params, *bc);
    
    std::ofstream file("solution.csv");
    for (double u : grid.u) file << u << ",";
    file.close();
    
    delete bc;
    return 0;
}
