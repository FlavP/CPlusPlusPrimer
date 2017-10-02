/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   brass.h
 * Author: flavius
 *
 * Created on October 2, 2017, 12:48 PM
 */
#include <cstring>

#ifndef BRASS_H
#define BRASS_H

class Brass{
private: 
    std::string fullName;
    long account;
    double balance;
public:
    Brass(const std::string & s="No name", long acc=-1, double bal=0.0);
    void Deposit(double amount);
    virtual void Withdraw(double amount);
    double Balance() const;
    virtual void ViewAccount() const;
    virtual ~Brass() {}
};

class BrassPlus : public Brass{
private:
    double maxAmount;
    double rate;
    double overDraft;
public:
    BrassPlus(const std::string & s= "No name plus", long acc=-1,
            double bal=0.0, double ml=500, double r=0.11125);
    BrassPlus(const Brass & brra, double ml=500, double r=0.11125);
    virtual void ViewAccount() const;
    virtual void Withdraw(double amount);
    void RestMax(double m){maxAmount = m;}
    void ResetR(double r){rate = r;}
    void ResetOver(){overDraft = 0;}
};


#endif /* BRASS_H */

