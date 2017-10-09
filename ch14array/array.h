/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   array.h
 * Author: flavius
 *
 * Created on October 9, 2017, 12:48 PM
 */

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstdlib>

template <typename T, int n>
class ArrayTP{
private:
    T ar[n];
public:
    ArrayTP(){};
    explicit ArrayTP(const T & v);
    virtual T & operator[](int i);
    virtual T operator[](int i) const;
};

template <typename T, int n>
ArrayTP<T,n>::ArrayTP(const T & v){
    int i;
    for(i = 0; i < n; i++){
        ar[i] = v;
    }    
}

template <typename T, int n>
T & ArrayTP<T,n>::operator [](int i){
    if(i < 0 || i >= n){
        std::cerr << "Error in array limits: " << i
                << " is out of range\n";
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}

template<typename T, int n>
T ArrayTP<T, n>::operator [](int i) const{
    if(i < 0 || i >= n){
        std::cerr << "Error in array limits: " << i
                << " is out of range\n";
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}

#endif /* ARRAY_H */

