# Simple boid simulation using Immaginary numbers
This 2D boids simulation aims to exchange angle calculations with immaginary numbers as a representation of the orientation of a boid in a bidimentional space.

## Index
[Complex numbers implementation](#complex-numbers-implementation)

## Complex numbers implementation
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


