/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   badharm.h
 * Author: flavius
 *
 * Created on October 11, 2017, 3:34 PM
 */

#ifndef BADHARM_H
#define BADHARM_H
#include <iostream>

class bad_hmean{
private:
    double v1, v2;
public:
    bad_hmean(double a, double b) : v1(a), v2(b){}
    void err_msg();
};

inline void bad_hmean::err_msg(){
    std::cout << "hmean (" << v1 << " " << v2 << ")" 
            << "Invalid arguments, a = -b" << std::endl;
}

class bad_gmean{
private:
    double v1, v2;
public:
    bad_gmean(double a, double b) : v1(a), v2(b){}
    const char * err_msg();
};

inline const char * bad_gmean::err_msg(){
    return "gmean() arguments should be > than 0";
}

#endif /* BADHARM_H */

