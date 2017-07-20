/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "timer.h"

Timer::Timer(){
    hours = minutes = 0;
}

Timer::Timer(int h, int m){
    hours = h;
    minutes = m;
}

void Timer::AddMin(int m){
    minutes += m;
    hours += minutes/60;
    minutes %= 60;
}

void Timer::AddHr(int h){
    hours += h;
}

void Timer::Reset(int h, int m){
    hours = h;
    minutes = m;
}
Timer Timer::operator+ (const Timer& t) const{
    Timer sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Timer Timer::operator*(double r) const{
    Timer prod;
    prod.minutes = minutes * r;
    prod.hours = hours * r;
    prod.hours += prod.minutes / 60;
    prod.minutes %= 60;
    return prod;
}

std::ostream & operator<< (std::ostream & os, const Timer & t){
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os; // the object returned is the object passed
}

Timer operator*(double r, const Timer & t){
    return t * r;
}