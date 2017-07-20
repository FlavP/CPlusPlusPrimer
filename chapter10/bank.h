/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bank.h
 * Author: flavius
 *
 * Created on July 6, 2017, 3:34 PM
 */

#ifndef BANK_H
#define BANK_H
#include <string>

class BankAccount{
private:
    std::string owner;
    std::string accno;
    double balance;
public:
    BankAccount();
    BankAccount(const std::string ow, const std::string acc="None", 
    double bal=0.0);
    ~BankAccount();
    void showAccount() const;
    void deposit(double n);
    void withdraw(double n);
};

#endif /* BANK_H */

