/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   complex0.h
 * Author: flavius
 *
 * Created on July 20, 2017, 12:59 PM
 */
#include <iostream>
#ifndef COMPLEX0_H
#define COMPLEX0_H

class Complex{
private:
    double r;
    double i;
public:
    Complex();
    Complex(double x, double y = 0);
    ~Complex();
    double get_r() const {return r;}
    double get_i() const {return i;}
    Complex operator+(const Complex &) const;
    Complex operator-(const Complex &) const;
    Complex operator*(const double) const;
    Complex operator*(const Complex &) const;
    Complex operator~() const;
    //friends
    friend Complex operator*(double x, const Complex & a);
    friend std::ostream & operator<<(std::ostream & os, const Complex & a);
    friend std::istream & operator>>(std::istream & is, Complex & a);
};


#endif /* COMPLEX0_H */

