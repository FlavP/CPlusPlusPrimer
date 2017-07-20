/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cmath>
#include <iostream>
#include "vector.h"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR{
    const double Radian_to_deg = 45.0 / atan(1.0);
    //private methods
    void Vector::set_mag(){
        mag = sqrt(x * x + y * y);
    }
    
    void Vector::set_ang(){
        if(x == 0 && y == 0)
            ang = 1;
        else
            ang = atan2(y, x);                
        }
    //set x from polar coordinates
    void Vector::set_x(){
        x = mag * cos(ang);
    }
    
    void Vector::set_y(){
        y = mag * sin(ang);
    }
    
    //public methods
    
    Vector::Vector(){
        x = y = mag = ang = 0.0;
        mode = Rect;
    }
    
    Vector::Vector(double n1, double n2, Mode form){
        mode = form;
        if (form == Rect){
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if(form == Pol){
            mag = n1;
            ang = n2 / Radian_to_deg;
            set_x();
            set_y();
        }
        else{
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = Rect;
        }
    }
    
    void Vector::reset(double n1, double n2, Mode form){
        if(form == Rect){
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if(form == Pol){
            mag = n1;
            ang = n2 / Radian_to_deg;
            set_x();
            set_y();
        }
        else{
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = Rect;
        }       
    }
    
    Vector::~Vector(){}
    
    // operator overloading
    
    Vector Vector::operator +(const Vector& t) const{
        return Vector(x + t.x, y + t.y);
    }
    
    Vector Vector::operator -(const Vector& t) const{
        return Vector(x - t.x, y - t.y);
    }
    
    Vector Vector::operator -() const{
        return Vector(-x, -y);
    }
    
    Vector Vector::operator *(double n) const{
        return Vector(n * x, n * y);
    }
    
    void Vector::rect_mode(){
        mode = Rect;
    }
    
    void Vector::polar_mode(){
        mode = Pol;
    }
    
    //friends
    
    Vector operator*(double n, const Vector & t){
        return t * n;
    }
    
    std::ostream & operator<<(std::ostream & os, const Vector & t){
        if(t.mode == Vector::Rect){
            os << "(x, y) = (" << t.x << ", " << t.y << ")";
        }
        else if(t.mode == Vector::Pol){
            os << "(m, a) = (" << t.mag << ", " << t.ang << ")";
        }
        else
            os << "Incorrect 3rd argument to Vector() -- ";
        return os;
    }
}


