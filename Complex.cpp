//
// Created by chaosmyth on 15/12/2017.
//

#include "Complex.h"

using namespace::std;

#include <cmath>
#include <iostream>
#include "Complex.h"

using namespace std;

Complex::Complex() :
        real(0), imag(0) {}


Complex::Complex(double r, double i)
{
    this->real = r;
    this->imag = i;
}

Complex Complex::operator+(Complex a)
{
    return {real + a.real, imag + a.imag};
}

Complex Complex::operator-(Complex a)
{
    return {real - a.real, imag - a.imag};
}

Complex Complex::operator*(Complex a)
{
    return {real*a.real-imag*a.imag, real*a.imag + imag*a.real};
}

Complex Complex::operator/(Complex a)
{
    return (this->operator*(a.conjugate())).operator/(a.real*a.real+a.imag*a.imag);
}

Complex Complex::pow(int n)
{
    Complex temp = *this;
    Complex ans = temp;
    for(int i = 0; i < n - 1; i++)
        ans = ans * temp;
    return ans;
}


Complex Complex::conjugate()
{
    return {this->real, -this->imag};
}

bool Complex::isReal()
{
    return imag == 0;
}

Complex Complex::operator/(double a)
{
    return {real/a, imag/a};
}

double Complex::getImag()
{
    return imag;
}

double Complex::getReal()
{
    return real;
}

string Complex::Show() {
    std::string str;
    std::string realStr = isInt(real) ? to_string(int(real)) : to_string(real);
    std::string imagStr = isInt(imag) ? to_string(int(imag)) : to_string(imag);
    if (real) {
        str = realStr;
        if(imag > 0)
            str += "+" + imagStr + "i";
        else if(imag < 0)
            str += imagStr + "i";
    }
    else if(imag)
        str = imagStr + "i";
    else
        str = "0";
    return str;
}

void Complex::setReal(int &newReal) {
    real = newReal;
}

void Complex::setImag(int &newImag) {
    imag = newImag;
}

void Complex::setReal(double &newReal) {
    real = newReal;
}

void Complex::setImag(double &newImag) {
    imag = newImag;
}


bool Complex::isInt(double a)
{
    double temp;
    return fabs(modf(a, &temp)) <= 1e-7;
}
