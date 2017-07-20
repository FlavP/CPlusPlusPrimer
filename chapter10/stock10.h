/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stock10.h
 * Author: flavius
 *
 * Created on July 5, 2017, 6:26 PM
 */

#ifndef STOCK10_H
#define STOCK10_H
#include <string>

class Stock{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_total() {total_val = shares * share_val;}
public:
    //two constructors, one default
    Stock();
    Stock(const std::string & co, long n = 0, double pr = 0.0);
    ~Stock(); //destructor
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show() const;
    const Stock & topvall(const Stock &) const;
};
#endif
