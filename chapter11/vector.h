/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vector.h
 * Author: flavius
 *
 * Created on July 19, 2017, 2:03 PM
 */

#include <iostream>
#ifndef VECTOR_H
#define VECTOR_H

namespace VECTOR{
    class Vector{
    public:
        enum Mode{Rect, Pol}; // rectangular or polar representation
    private:
        double x; //coordonata pe x
        double y; //coordonata pe y
        double mag; //lungimea vectorului
        double ang; //unghiul vectorului
        Mode mode;
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
        Vector();
        Vector(double x, double y, Mode form=Rect);
        void reset(double x, double y, Mode form=Rect);
        ~Vector();
        double get_x() const { return x;}
        double get_y() const { return y;}
        double get_mag() const { return mag; }
        double get_ang() const { return ang; }
        void polar_mode();
        void rect_mode();
        // operator overloading
        Vector operator+(const Vector & t) const;
        Vector operator-(const Vector & t) const;
        Vector operator-() const;
        Vector operator*(double n) const;
        //friends
        friend Vector operator*(double n, const Vector & t);
        friend std::ostream & operator<<(std::ostream & os, const Vector & t);
    };
}


#endif /* VECTOR_H */

