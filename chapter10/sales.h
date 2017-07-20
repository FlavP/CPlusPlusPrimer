/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sales.h
 * Author: flavius
 *
 * Created on July 7, 2017, 12:08 PM
 */

#ifndef SALES_H
#define SALES_H
static const int QUARTERS = 4;
    
    
class Sales{
private:    
    struct salestruct{
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    };
    salestruct s;
public:
    Sales();
    Sales(const double ar[], int n);
    void setSales();
    void showSales();
    ~Sales();
};

#endif /* SALES_H */

