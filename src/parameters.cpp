#include "parameters.h"

Parameters::Parameters(double c, double dx, double CFL, double t_max) : c(c), t_max(t_max) {
    dt = CFL * dx / c;
    steps = static_cast<int>(t_max / dt);
}


