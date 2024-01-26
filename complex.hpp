#include <cmath>

class Complex {
    private:
    double real;
    double imaginary;
    
    public:
    // constructor
    Complex(double r, double i): real{r}, imaginary{i} {}; 
    // operator Complex + Complex
    Complex operator+(Complex const& obj) {
        return Complex(real+obj.real, imaginary+obj.imaginary);
    }
    // operator Complex +=
    Complex operator+=(Complex const& obj) {
        real = real+obj.real;
        imaginary = imaginary+obj.imaginary;
    }
    // operator ==
    bool Complex::operator==(Complex const& obj) {
        return (real==obj.real && imaginary==obj.imaginary);
    }
    // operator Complex*Scalar
    Complex operator*(double const& obj) {
        return Complex(real*obj, imaginary*obj);
    }
    // operator Complex/Scalar
    Complex operator/(double const& obj) {
        return Complex(real/obj, imaginary/obj);
    }
    // operator Complex*Complex
    Complex operator*(Complex const& obj) {
        return Complex(real*obj.real - imaginary*obj.imaginary, real*obj.imaginary + imaginary*obj.real);
    }
    // operator Complex conjugate
    Complex operator~() {
        return Complex(real, -imaginary);
    }
    // modulus
    double Complex::modulus() {
        return std::sqrt(real*real + imaginary*imaginary);
    }
    // radians angle convertion
    double Complex::rad() {
        // accounting fot atan range being [-M_PI, M_PI], we add ora subtract M_PI to obtain radians for numbers in range [M_PI, -M_PI]
        if(real<0) {
            if(imaginary<0){
                return (atan(imaginary/real) + M_PI);
            }
            return (atan(imaginary/real) - M_PI);
        }
        return atan(imaginary/real);
    }
    // real component 
    double Complex::getReal() {
        return real;
    }
    // imaginary component
    double Complex::getImaginary() {
        return imaginary;
    }

};
