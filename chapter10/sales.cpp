/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "sales.h"

Sales::Sales(){
    std::cout << "Using the default constructor\n";
    std::cout << "Everything is set to 0\n";
    s.average = 0.0;
    s.max = 0.0;
    s.sales[0] = 0.0;
    s.min = 0.0;
}

Sales::Sales(const double ar[], int n){
    double arg[n];
    int i, j;
    double temp;
    double sum = 0;
    for(i = 0; i < n; i++)
        arg[i] = ar[i];
    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            if(arg[i] > arg[j]){
                temp = arg[i];
                arg[i] = arg[j];
                arg[j] = temp;
            }
        }
    }
    
    for(i = 0; i < QUARTERS; i++){
        s.sales[i] = arg[i];
        sum += s.sales[i];
    }
    s.min = s.sales[0];
    s.max = s.sales[QUARTERS - 1];
    s.average = sum / QUARTERS;
}

void Sales::setSales(){
    using std::cout;
    using std::cin;
    double min, max;
    double sum = 0;
    int i = 0;
    for(i = 0; i < QUARTERS; i++){
        cout << "Element " << i + 1 << " is: " << std::endl;
        cin >> s.sales[i];
    }
    min = max = s.sales[0];
    for(i = 0; i < QUARTERS; i++){
        sum += s.sales[i];
        if(min > s.sales[i])
            min = s.sales[i];
        if(max < s.sales[i])
            max = s.sales[i];
    }
    s.max = max;
    s.min = min;
    s.average = sum/QUARTERS;
}

void Sales::showSales(){
    using std::cout;
    for(int i = 0; i < QUARTERS; i++){
        cout << "Element " << i + 1 << " is: " << s.sales[i] << std::endl;
    }
    cout << "Minim is: " << s.min << std::endl;
    cout << "Maxim is: " << s.max << std::endl;
    cout << "Average is: " << s.average << std::endl;
}

Sales::~Sales(){
    std::cout << "Class destructor has been called\n";
}