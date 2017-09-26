/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <string>
#include "string12.h"

int String12::num_of_strings = 0;

String12::String12(const char* s){
    std::cout << "Constructor in action\n";
    len = std::strlen(s) + 1;
    str = new char[len];
    std::strcpy(str, s);
    num_of_strings++;
    std::cout << "Current number of strings is: " << num_of_strings << "\n";
}

String12::String12(){
    std::cout << "Default constructor called\n";
    len = 4;
    str = new char[len];
    std::strcpy(str, "C++");
    num_of_strings++;
    std::cout << "Current number of strings is: " << num_of_strings << "\n";    
}

String12::String12(const String12 & st){
    num_of_strings++;
    len = st.len + 1;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    std::cout << "Object created " << num_of_strings << " available\n";
}

String12::~String12(){
    std::cout << "Default destructor called\n";
    num_of_strings--;
    delete [] str;
    std::cout << "Current number of strings left is: " << num_of_strings << "\n";    
}

std::ostream & operator<<(std::ostream & os, const String12 & st){
    os << st.str << "\n";
    return os;
}

String12 & String12::operator =(const String12 & st){
    if(this == &st){
        return *this;
    }
    delete [] str;
    len = std::strlen(st.str) + 1;
    str = new char[len];
    std::strcpy(str, st.str);
    return *this;
}
