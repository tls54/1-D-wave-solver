#ifndef PARAMETERS_H
#define PARAMETERS_H

class Parameters {
public:
    double c, dt, t_max;
    int steps;
    Parameters(double c, double dx, double CFL, double t_max);
};

#endif
