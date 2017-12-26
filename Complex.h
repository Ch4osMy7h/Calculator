//
// Created by chaosmyth on 15/12/2017.
//

#ifndef CALCULATOR_COMPLEX_H
#define CALCULATOR_COMPLEX_H

#include <string>

class Complex
{
public:
    Complex();
    Complex(double r, double i = 0);
    Complex operator+(Complex a);
    Complex operator-(Complex a);
    Complex operator*(Complex a);
    Complex operator/(Complex a);
    Complex operator/(double a);
    Complex pow(int n);
    Complex conjugate();
    bool isReal();
    double getImag();
    double getReal();
    void setReal(double& newReal);
    void setImag(double& newImag);
    void setReal(int& newReal);
    void setImag(int& newImag);
    std::string Show();
private:
    double imag, real;
    bool isInt(double a);

};

#endif //CALCULATOR_COMPLEX_H
