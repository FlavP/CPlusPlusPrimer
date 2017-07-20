/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "bank.h"

using std::cout;
BankAccount::BankAccount(){
    cout << "Default constructor has been called\n";
    owner = "None";
    accno = "None";
    balance = 0;
}

BankAccount::BankAccount(const std::string ow, const std::string acc, double bal){
    owner = ow;
    accno = acc;
    balance = bal;
}

BankAccount::~BankAccount(){
    cout << "Destructor has been called\n";
}

void BankAccount::showAccount() const{
    cout << "Owner is: " << owner << std::endl;
    cout << "Account number: " << accno << std::endl;
    cout << "Balance is: " << balance << std::endl;
}

void BankAccount::deposit(double n){
    balance += n;
    cout << n << " roni have been added \n";
    cout << "New balance is: " << balance << std::endl;
}

void BankAccount::withdraw(double n){
    balance -= n;
    cout << n << " roni have been withdrawn \n";
    cout << "New balance is: " << balance << std::endl;
}