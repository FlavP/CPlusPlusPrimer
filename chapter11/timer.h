/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   timer.h
 * Author: flavius
 *
 * Created on July 10, 2017, 1:33 PM
 */

#ifndef TIMER_H
#define TIMER_H
#include <iostream>

class Timer{
private:
    int hours;
    int minutes;
public:
    Timer();
    Timer(int h, int m=0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h=0, int m=0);
    Timer operator+(const Timer & t) const;
    Timer operator*(double r) const;
    friend Timer operator*(double r, const Timer & t);
    friend std::ostream & operator<<(std::ostream & os, const Timer & t); // reference for ( cout << x << y)   
};


#endif /* TIMER_H */

