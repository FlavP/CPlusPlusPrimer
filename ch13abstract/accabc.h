/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   accabc.h
 * Author: flavius
 *
 * Created on October 3, 2017, 12:56 PM
 */

#ifndef ACCABC_H
#define ACCABC_H
#include <iostream>
#include <string>

class AccABC{
private:
    std::string fname;
    long account;
    double balance;
protected:
    struct Format{
        std::ios_base::fmtflags flag;
        std::streamsize p;
    };
    const std::string & returnName() const {return fname;}
    long returnAcc() const {return account;}
    Format arrange() const;
    void Restore(Format & f) const;
public:
    AccABC(const std::string & s = "No name", long accnum = -1,
           double balance = 0.0);
    double showBalance() const {return balance;}
    void Deposit(double d);
    virtual void Withdraw(double d) = 0;
    virtual void showAcc() const = 0;
    virtual ~AccABC() {};
};

class Brass : public AccABC{
public:
    Brass(const std::string & s = "No name", long accnum = -1,
           double balance = 0.0) : AccABC(s, accnum, balance) {}
    virtual void Withdraw(double d);
    virtual void showAcc() const;
    virtual ~Brass() {}
};

class BrassPlus : public AccABC{
private:
    double maxAmount;
    double rate;
    double overdraft;
public:
    BrassPlus(const std::string & s = "No name", long accnum = -1,
            double balance = 0.0, double am = 500, double r = 0.12);
    BrassPlus(const Brass & bra, double am = 500, double r = 0.12);
    virtual void showAcc() const;
    virtual void Withdraw(double d);
    void ResetAmount(double d){maxAmount = d;}
    void ResetRate(double d){rate = d;}
    void ResetDraft(){overdraft = 0;}
};
#endif /* ACCABC_H */

