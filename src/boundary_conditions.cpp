#include "boundary_conditions.h"
#include <iostream>

// Definition of apply method for DirichletBC
void DirichletBC::apply(std::vector<double>& u) {
    u[0] = u[u.size() - 1] = 0.0;
}

// Definition of apply method for NeumannBC
void NeumannBC::apply(std::vector<double>& u) {
    u[0] = u[1];
    u[u.size() - 1] = u[u.size() - 2];
}

// Factory function for creating boundary condition objects
BoundaryConditions* createBoundaryCondition(const std::string& type) {
    if (type == "dirichlet") return new DirichletBC();
    if (type == "neumann") return new NeumannBC();
    std::cerr << "Unknown boundary condition: " << type << "\n";
    return nullptr;
}

// Function to create initial condition based on a string type
double createInitialCondition(const std::string& type, double x) {
    if (type == "pulse") return (x > 0.4 && x < 0.6) ? 1.0 : 0.0;
    if (type == "sinusoid") return std::sin(2 * M_PI * x);
    return 0.0;
}