/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "complex0.h"

Complex::Complex(){
    r = i = 0;
}

Complex::Complex(double x, double y){
    r = x;
    i = y;
}

Complex::~Complex(){}

Complex Complex::operator +(const Complex& x) const{
    return Complex(r + x.r, i + x.i);
}

Complex Complex::operator -(const Complex& x) const{
    return Complex(r - x.r, i - x.i);
}

Complex Complex::operator *(const double n) const{
    return Complex(r * n, i * n);
}

Complex Complex::operator *(const Complex& x) const{
    return Complex(r * x.r - i * x.i, r * x.i + i * x.r);
}

Complex Complex::operator ~() const{
    return Complex(r, -i);
}

Complex operator*(double n, const Complex & a){
    return a * n;
}

std::ostream & operator<<(std::ostream & os, const Complex & a){
    if(a.i > 0){
        return os << a.r << '+' << a.i << 'i';
    }
    else{
        return os << a.r << a.i << 'i';
    }
}

std::istream & operator>>(std::istream & is, Complex & a){
    is >> a.r >> a.i;
    return is;
}