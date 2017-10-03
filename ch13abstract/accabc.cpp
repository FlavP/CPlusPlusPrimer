/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "accabc.h"

using std::cout;
using std::ios_base;
using std::endl;
using std::string;

AccABC::AccABC(const std::string & s, long l, double bala){
    fname = s;
    account = l;
    balance = bala;
}

void AccABC::Deposit(double d){
    if(d < 0.0){
        cout << "The amount can't be negative. "
                << "Operation canceled" << endl;
    }
    else{
        balance += d;
    }
}

void AccABC::Withdraw(double d){
    balance -= d;
}

AccABC::Format AccABC::arrange() const{
    Format f;
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.p = cout.precision(2);
    return f;
}

void AccABC::Restore(Format& f) const{
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.p);
}

void Brass::Withdraw(double d){
    if(d < 0){
        cout << "The amount must be positive. "
                << "Operation canceled\n";
    }
    else if(d <= showBalance()){
        AccABC::Withdraw(d);
    }
    else{
        cout << "This amount exceeds your budget. "
               << "Operation canceled\n"; 
    }
}

void Brass::showAcc() const{
    Format f = arrange();
    cout << "Client: " << returnName() << endl;
    cout << "Account Number: " << returnAcc() << endl;
    cout << "Balance: " << showBalance() << endl;
    Restore(f);
}

BrassPlus::BrassPlus(const std::string& s, long accnum, double balance,
        double am, double r) : AccABC(s, accnum, balance){
    maxAmount = am;
    rate = r;
    overdraft = 0.0;
}

BrassPlus::BrassPlus(const Brass& bra, double am, double r) : AccABC(bra){
    maxAmount = am;
    rate = r;
    overdraft = 0.0;
}

void BrassPlus::Withdraw(double d){
    Format f = arrange();
    double bla = showBalance();
    if(d <= bla){
        AccABC::Withdraw(d);
    }
    else if(d <= bla + maxAmount - overdraft){
        double front = d - bla;
        overdraft += front * (1.0 + rate);
        cout << "Bank advance: " << front << endl;
        cout << "Charge: " << front * rate << endl; 
        Deposit(front);
        AccABC::Withdraw(d);
    }
    else{
        cout << "This amount exceeds your budget. "
               << "Operation canceled\n";     
    }
    Restore(f);
}

void BrassPlus::showAcc() const{
    Format f = arrange();
    cout << "Client: " << returnName() << endl;
    cout << "Account Number: " << returnAcc() << endl;
    cout << "Balance: " << showBalance() << endl;    
    cout << "Maximum Overdraft: " << maxAmount << endl;
    cout << "Current Overdraft: " << overdraft << endl;    
    cout.precision(3);
    cout << "Loan Rate: " << rate * 100 << "%\n";   
    Restore(f);    
}