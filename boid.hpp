#include "complex.hpp"

class Boid {
    private:
    // orientation
    Complex angle;
    // coordinates
    double x;
    double y;
    // speeds
    double vX;
    double vY;

    public:   
    // constructor
    Boid(double r, double i, double x, double y, double vX, double vY): angle(r,i), x{x}, y{y}, vX{vX}, vY{vY} {};
    Boid(Complex orient, double x, double y, double vX, double vY): angle{orient}, x{x}, y{y}, vX{vX}, vY{vY} {};
    // other methods
    Boid Boid::move(){};
};
