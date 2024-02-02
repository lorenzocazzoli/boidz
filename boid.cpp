#include "boid.hpp"

// I still need to think about how to implement constants used in all the document
// such as maxDistance, sightAngle, minDistance and the three coefficients
// for the time being I'll put them here
double maxDistance = 0;
double minDistance = 0;
double repulsionFactor = 1;
double attractionFactor = 1;
double mVelocityFactor = 1;
std::vector<Boid> allBoids;
double deltaT = 1;

std::vector<int> Boid::flock(const std::vector<Boid>& list) {
    std::vector<int> flockmatesIndex;
    for(int i=0; i<list.size(); i++) {
        if(this->distance(list[i]) > maxDistance)
            continue;
        if(!this->sight(list[i]))
            continue;
        flockmatesIndex.push_back(i);
    }
    return flockmatesIndex;
}

Complex Boid::force(const std::vector<int>& list){
    Complex newSpeed(0,0);
    for (int i = 0; i<list.size(); i++) {
        newSpeed += this->repulsion(list);
        newSpeed += this->attraction(list);
        newSpeed += this->mVelocity(list);
    }
    return newSpeed;
}

Complex Boid::repulsion(const std::vector<int>& list) {
    double real = 0;
    double imaginary = 0;
    for (int i=0; i<list.size(); i++) {
        if(this->distance(allBoids[list[i]]) > minDistance)
            continue;
        real += repulsionFactor/this->distanceXY(allBoids[list[i]])[0];
        imaginary += repulsionFactor/this->distanceXY(allBoids[list[i]])[1];
    }
    Complex repulsionSpeed(real, imaginary);
    return repulsionSpeed;
}

Complex Boid::attraction(const std::vector<int>& list) {
    double real = 0;
    double imaginary = 0;
    for(int i=0; i<list.size(); i++) {
        if (this->distance(allBoids[list[i]]) < minDistance)
            continue;
        real += attractionFactor*this->distanceXY(allBoids[list[i]])[0];
        imaginary += attractionFactor*this->distanceXY(allBoids[list[i]])[1];
    }
    Complex attractionSpeed(real, imaginary);
    return attractionSpeed;
}

Complex Boid::mVelocity(const std::vector<int>& list) {
    double real = 0;
    double imaginary = 0;
    for(int i=0; i<list.size(); i++) {
        real += allBoids[list[i]].getSpeed().getReal();
        imaginary += allBoids[list[i]].getSpeed().getImaginary();
    }
    real = real/list.size(); 
    imaginary = imaginary/list.size();
    Complex meanVelocitySpeed(real-this->getSpeed().getReal(), imaginary-this->getSpeed().getImaginary());
    return meanVelocitySpeed*mVelocityFactor;
}

std::vector<double> Boid::move(const double dt){
    double newX = this->getX() + this->getSpeed().getReal()*dt;
    double newY = this->getY() + this->getSpeed().getImaginary()*dt;
    std::vector<double> newCoord(newX, newY);
    return newCoord;
}