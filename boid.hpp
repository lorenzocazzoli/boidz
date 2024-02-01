#include "complex.hpp"
#include <vector>

class Boid {
    private:
    // orientation and speed
    Complex speed;
    // coordinates
    std::vector<double> coord;

    public:   
    // ------------------- //
    //    CONSTRUCTORS     //
    // ------------------- //

    // four doubles constructor
    Boid(double r, double i, double x, double y): speed(r,i) {coord.push_back(x); coord.push_back(y);};
    // complex and two doubles constructor 
    Boid(const Complex& orient, double x, double y): speed{orient}  {coord.push_back(x); coord.push_back(y);};
    // two doubles and a vector
    Boid(double r, double i, const std::vector<double>& c): speed(r,i), coord{c} {};
    // complex and vector
    Boid(const Complex& orient, const std::vector<double>& c): speed(orient), coord{c} {};

    // ------------------- //
    //         GET         //
    // ------------------- //

    // gets x or y coordinates directly
    double Boid::getX(){return coord[0];};
    double Boid::getY(){return coord[1];};
    // gets both coordinates directly
    std::vector<double> Boid::getCoord(){return coord;};
    // gets boid's speed 
    //  -> to get real or imaginary components use Complex methods
    Complex Boid::getSpeed(){return speed;};
    
    // ------------------- //
    //    UPDATE METHODS   //
    // ------------------- //

    // creates a list of flockmates by storing their index from the general Boids list
    std::vector<int> Boid::flock(const std::vector<Boid>& list){};
    // force updates the speed value according to behaviour rules
    Complex Boid::force(){};
    // line of sight between boids
    bool Boid::sight(const Boid& obj){};
    // distance between boids
    double Boid::distance(const Boid& obj){};
    // repulsion rule 
    Complex Boid::repulsion(const std::vector<int>& list){};
    // attraction rule
    Complex Boid::attraction(const std::vector<int>& list){};
    // mean velocity rule
    Complex Boid::mVelocity(const std::vector<int>& list){};

    // move updates the coordinates value according to speed value
    std::vector<double> Boid::move(){};
};
