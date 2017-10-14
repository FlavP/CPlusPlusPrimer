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
#include <string>
#include <stdexcept>


class bad_hmean : public std::logic_error{
private:
    double v1, v2;
public:
    bad_hmean(double a, double b, const std::string & st = "Bad harmonic") 
            : v1(a), v2(b), std::logic_error(st){}
    void err_msg();
    ~bad_hmean() throw(){}
};

inline void bad_hmean::err_msg(){
    std::cout << "hmean (" << v1 << " " << v2 << ")" 
            << "Invalid arguments, a = -b" << std::endl;
}

class bad_gmean : public std::logic_error{
private:
    double v1, v2;
public:
    bad_gmean(double a, double b, const std::string & st = "Bad geometric")
            : v1(a), v2(b), std::logic_error(st){}
    const char * err_msg();
    ~bad_gmean() throw(){}
};

inline const char * bad_gmean::err_msg(){
    return "gmean() arguments should be > than 0";
}

#endif /* BADHARM_H */

