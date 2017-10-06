/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   abcsource.h
 * Author: flavius
 *
 * Created on October 6, 2017, 12:25 PM
 */

#ifndef ABCSOURCE_H
#define ABCSOURCE_H
#include <iostream>
#include <string>

using std::string;

class AbcDMA{
private:
    string name;
    string message;
public:
    AbcDMA(const string & s1="No name", const string & s2="No message");
    AbcDMA(const AbcDMA & aby);
    virtual ~AbcDMA(){}
    virtual void ShowDMA() const = 0;
    virtual AbcDMA & operator=(const AbcDMA & abi);
    string returnName() const {return name;}
    string returnMess() const {return message;}
};

class BaseDMA : public AbcDMA{
private:
    string inplus;
public:
    BaseDMA(const string &inplus="No plus", const string & s1="No name", 
            const string & s2="No message");
    BaseDMA(const string &inplus, const AbcDMA & abi);
    virtual ~BaseDMA(){}
    virtual void ShowDMA() const;
    virtual BaseDMA & operator=(const BaseDMA & babi);
};

class HasDMA : public BaseDMA{
private:
    string inminus;
public:
    HasDMA(const string & inminus="No simbol", const string & inplus="No plus", 
            const string & s1="No name", const string & s2="No message");
    HasDMA(const string & inminus, const BaseDMA & babi);
    virtual ~HasDMA(){}
    virtual void ShowDMA() const;
    virtual HasDMA & operator=(const HasDMA & habi);
};

#endif /* ABCSOURCE_H */

