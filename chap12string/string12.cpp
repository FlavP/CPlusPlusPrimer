/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <cstring>
#include <cctype>
#include "string12.h"

int String12::num_of_strings = 0;

int String12::LengthOf(){
    return num_of_strings;
}

String12::String12(const char* s){
    std::cout << "Constructor in action\n";
    len = std::strlen(s) + 1;
    str = new char[len];
    std::strcpy(str, s);
    num_of_strings++;
    std::cout << "Object is " << str << "\n";
    std::cout << "Current number of strings is: " << num_of_strings << "\n";
}

String12::String12(){
    std::cout << "Default constructor called\n";
    str = new char[1];
    len = 4;
    str[0] = '\0';
    num_of_strings++;
    std::cout << "Current number of strings is: " << num_of_strings << "\n";
}

String12::String12(const String12 & st){
    num_of_strings++;
    len = st.len + 1;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    std::cout << "Object is " << str << "\n";
    std::cout << "Object created " << num_of_strings << " available\n";
}

String12::~String12(){
    std::cout << "Default destructor called\n";
    std::cout << "Object distroyed is " << str << "\n";
    --num_of_strings;
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
    len = st.len + 1;
    str = new char[len];
    std::strcpy(str, st.str);
    return *this;
}

String12 & String12::operator =(const char* ch){
    delete [] str;
    len = std::strlen(ch) + 1;
    str = new char[len];
    std::strcpy(str, ch);
    return *this;
}

bool operator >(const String12 & s1, const String12 & s2){
    return (std::strcmp(s1.str, s2.str) < 0);
}

bool operator <(const String12 & s1, const String12 & s2){
    return s2 < s1;
}

bool operator ==(const String12 & s1, const String12 & s2){
    return(std::strcmp(s1.str, s2.str) == 0);
}

char & String12::operator [](int i){
    return str[i];
}

const char & String12::operator [](int i) const{
    return str[i];
}

std::istream & operator>>(std::istream & is, String12 & st){
    char temp[String12::LIM];
    is.get(temp, String12::LIM);
    if(is)
        st = temp;
    while(is && is.get() != '\n')
        continue;
    return is;
}

String12 String12::operator +(const String12& s){
    String12 gigel;
    gigel.len = len + s.len + 1;
    std::strcpy(gigel.str, str);
    std::strcat(str, s.str);
    return gigel;
}

String12 operator+(const char *ch, const String12 & ustr){
    int lengthch = std::strlen(ch);
    char ajut[lengthch + 1];
    std::strcpy(ajut, ch);
    int i = lengthch + ustr.len + 1;  
    String12 gigel;
    std::strcpy(gigel.str, ajut);
    std::strcat(gigel.str, ustr.str);
    gigel.len = i;
    return gigel;    
}

void String12::stringlow(){
    char * ch = &str[0];
    while(*ch != '\0'){
        if(std::isalpha(*ch)){
            std::cout << *ch;
        }
        ch++;
    }
}

void String12::stringup(){
    //std::cout << "Sunt in stringup";
    char * ch = &str[0];
    while(*ch != '\0'){
        if(std::isalpha(*ch)){
            std::toupper(*ch);
        }
        ch++;
    }
    std::cout << str;
}

int String12::howMany(char ch){
    int counter = 0;
        char * pch = &str[0];
    while(*pch != '\0'){
        if(*pch == ch){
            counter++;
        }
        pch++;
    }
    return counter;
}