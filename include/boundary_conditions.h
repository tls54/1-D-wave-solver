#ifndef BOUNDARY_CONDITIONS_H
#define BOUNDARY_CONDITIONS_H

#include <vector>
#include <string>

class BoundaryConditions {
public:
    // Virtual destructor ensures proper cleanup of derived class objects
    virtual ~BoundaryConditions() = default;

    // Pure virtual function to apply boundary condition
    virtual void apply(std::vector<double>& u) = 0;
};

class DirichletBC : public BoundaryConditions {
public:
    // Declaration of apply function
    void apply(std::vector<double>& u) override;
};

class NeumannBC : public BoundaryConditions {
public:
    // Declaration of apply function
    void apply(std::vector<double>& u) override;
};

// Factory function for creating boundary condition objects
BoundaryConditions* createBoundaryCondition(const std::string& type);

// Function to create initial condition based on a string type
double createInitialCondition(const std::string& type, double x);

#endif