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


class bad_mean : public std::logic_error{
    private:
        double v1, v2;
    public:
        bad_mean(double a, double b, const std::string & st = "Bad mean") 
                : v1(a), v2(b), std::logic_error(st){}
        virtual void err_msg();
        virtual ~bad_mean() throw(){}        
};

inline void bad_mean::err_msg(){
    std::cout << v1 << ", " << v2 << std::endl;
}

class bad_hmean : public bad_mean{
public:
    bad_hmean(double a, double b, const std::string & st = "Bad harmonic") 
            : bad_mean(a, b, st){}
    void err_msg();
    virtual ~bad_hmean() throw(){}
};

inline void bad_hmean::err_msg(){
    std::cout << "hmean " << std::endl; 
    bad_mean::err_msg();
    std::cout << "Invalid arguments, a = -b" << std::endl;
}

class bad_gmean : public bad_mean{
public:
    bad_gmean(double a, double b, const std::string & st = "Bad geometric")
            : bad_mean(a, b, st){}
    inline void err_msg();
    virtual ~bad_gmean() throw(){}
};

inline void bad_gmean::err_msg(){
    std::cout << "gmean " << std::endl;
    bad_mean::err_msg();
    std::cout << "arguments should be > than 0";
}

#endif /* BADHARM_H */

