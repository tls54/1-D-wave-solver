#ifndef GRID_H
#define GRID_H

#include <vector>
#include <functional> 



class Grid {
public:
    int nx;
    double dx;
    std::vector<double> u, u_prev, u_next;
    
    Grid(int nx, double dx);
    void initialize(std::function<double(double)> init_func);
};

#endif
