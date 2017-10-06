/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <string>
#include "abcsource.h"

using std::cout;
using std::endl;
using std::string;

AbcDMA::AbcDMA(const string & s1, const string & s2){
    name = s1;
    message = s2;
}

AbcDMA::AbcDMA(const AbcDMA & aby){
    name = aby.name;
    message = aby.message;
}

AbcDMA & AbcDMA::operator =(const AbcDMA& abi){
        if(this == &abi)
            return *this;
        name = abi.name;
        message = abi.message;
        return *this;
}

BaseDMA::BaseDMA(const string& s3, const string& s1, const string& s2)
        : AbcDMA(s1, s2){
    inplus = s3;
}

BaseDMA::BaseDMA(const string& s, const AbcDMA& abi) : AbcDMA(abi){
    inplus = s;
}

BaseDMA & BaseDMA::operator =(const BaseDMA& babi){
    if(this == &babi)
        return *this;
    AbcDMA::operator=(babi);
    inplus = babi.inplus;
    return *this;
}

void BaseDMA::ShowDMA() const{
    cout << "Yaaay, abstract babi method\n";
    cout << "Name: " << AbcDMA::returnName() << endl;
    cout << "Message: " << AbcDMA::returnMess() << endl;
    cout << "In plus: " << inplus << endl;
}

HasDMA::HasDMA(const string & s4, const string& s3, const string& s1, 
        const string& s2)
        : BaseDMA(s3, s1, s2){
    inminus = s4;
}

HasDMA::HasDMA(const string& s, const BaseDMA& babi) : BaseDMA(babi){
    inminus = s;
}

HasDMA & HasDMA::operator =(const HasDMA& habi){
    if(this == &habi)
        return *this;
    BaseDMA::operator=(habi);
    inminus = habi.inminus;
    return *this;
}

void HasDMA::ShowDMA() const{
    cout << "Yaaay, abstract habi method\n";
    cout << "In plus: " << inminus << endl;
    BaseDMA::ShowDMA();
    cout << "In plus: " << inminus << endl;
}