/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   string12.h
 * Author: flavius
 *
 * Created on September 26, 2017, 11:40 AM
 */
#include <iostream>
#ifndef STRING12_H
#define STRING12_H

class String12{
private:
    char *str;
    int len;
    static int num_of_strings;
    static const int LIM = 80;
public:
    String12();
    String12(const char *s);
    String12(const String12 & st);
    ~String12();
    int length() const {return len; }      
    String12 & operator=(const String12 & st);
    String12 & operator=(const char * ch);
    friend std::ostream & operator<<(std::ostream & os, const String12 & str);
    friend bool operator>(const String12 & s1, const String12 & s2);
    friend bool operator<(const String12 & s1, const String12 & s2);
    friend bool operator==(const String12 & s1, const String12 & s2);
    friend std::istream & operator>>(std::istream & is, String12 & str);
    char & operator[](int i);
    const char & operator[](int i) const;
    static int LengthOf();
};

#endif /* STRING12_H */

