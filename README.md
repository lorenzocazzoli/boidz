# Simple boid simulation using Complex numbers
This 2D boids simulation aims to exchange angle calculations with immaginary numbers as a representation of the orientation of a boid in a bidimentional space.

I don't really understand why I should be using complex numbers.
Having written the first lines of code I can see I'm not really using Complex number properties, so I'll switch to a two number system and call it a day.
For the speeds we'll see, I'll manage with two double just fine, and I'll try not to convert to radians nor degrees, but keep it in double also for the orientation check.

## Index
* [Complex numbers implementation](#complex-numbers-implementation)
* [Boids implementation](#boids-implementation)
* [Compilation and execution](#compilation-test-and-executions-instructions)

# Complex numbers implementation
Complex numbers are defined by two double values, notation in the readme will use A as an example complex number defined as such:

> A = a + bi

```
double real;     // real component of a complex number          a
double imaginary // imaginary component of a complex number     b
```
Having a scalar value _r_ and B, another complex number defined as

> B = c +di

the operators and methods for complex numbers are implemented as follows:


* Operator + : A + B = (a + c) + (b + d)*i
* Operator * : A * B = (ac - bd) + (ad + bc)*i 
* Operator * (scalar) : A * _r_ = a*_r_ + b*_r_*i
* Operator / (scalar) is defined similarly  
* Operator == : A == B if a == c && b == d
* Operator ~ : returns conjugate number of argument
* modulus(A) returns the complex number's modulus
* rad(A)  returns the complex number's correspondent angle
* getReal and getImaginary respectively return the real and imaginary components of the complex number

# Boids implementation
Boids are the units moving in the simulation.
They are defined using one complex number for their speed and orientation, and one vector for their position.

Constructors allow to instantiate one using four double, a Complex and two double, two double and a vector or a Complex and a vector.

# Compilation test and executions instructions

[CMAKE](https://cmake.org/) is used to compile this project. 
To compile with CMAKE it's necessary to first configure the workspace by using the following commands inside the work directory:

```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug  // to use in development and test phase

cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=OFF // to build the executable file in production phase
```

This commands make the _build_ directory inside the current directory.
To compile and make the executable files inside _build_ dir use the following command:

```
cmake --build build
```

Two executable files will be created: "Boids" and "Boids.t", the first is the main program implementation and will start the boids simulation in executed, latter will launch the tests for the program.
To execute the files move inside the _build_ directory and use the following command:

```
./boids     //simulazione stormo

./boids.t   //esecuzione test
```
