/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "brass.h"

using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precizie;

format setForm();
void reset(format f, precizie p);

Brass::Brass(const std::string& s, long acc, double bal){
    fullName = s;
    account = acc;
    balance = bal;
}

void Brass::Deposit(double amount){
    if(amount < 0){
        cout << "Negative deposit is disallowed; " << "Operation canceled\n";
    }
    else{
        balance += amount;
    }
}

void Brass::Withdraw(double amount){
    format initial = setForm();
    precizie preci = cout.precision(2);
    if(amount < 0){
        cout << "Withdrawal amount must be greater than 0 "
                << "Operation canceled\n";
    }    
    else if(amount <= balance){
        balance -= amount;
    }
    else{
        cout << "The amount " << amount << " exceeds your balance\n"
                << "Operation canceled\n";
    }
}

double Brass::Balance() const{
    return balance;
}

void Brass::ViewAccount() const{
    format ini = setForm();
    precizie preci = cout.precision(2);
    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << account << endl;
    cout << "Balance: " << balance << endl;
    reset(ini, preci);
}

BrassPlus::BrassPlus(const std::string& s, long acc, 
        double bal, double ml, double r) : Brass(s, acc, bal){
    maxAmount = ml;
    overDraft = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & brra, double ml, double r) : Brass(brra){
    maxAmount = ml;
    overDraft = 0.0;
    rate = r;
}

void BrassPlus::ViewAccount() const{
    format initi = setForm();
    precizie preci = cout.precision(2);
    cout << "Maximum Overdraft: " << maxAmount << endl;
    cout << "Current Overdraft: " << overDraft << endl;    
    cout.precision(3);
    cout << "Loan Rate: " << rate * 100 << "%\n";   
    reset(initi, preci);
}

void BrassPlus::Withdraw(double amount){
    format initi = setForm();
    precizie preci = cout.precision(2);
    double ball = Balance();
    if(amount <= ball){
        Brass::Withdraw(amount);
    }
    else if(amount <= ball + maxAmount - overDraft){
        double owes = amount - ball;
        overDraft += owes * (1.0 + rate);
        cout << "Bank advance: " << owes << endl;
        cout << "Charge: " << owes * rate << endl;
        Deposit(owes);
        Brass::Withdraw(amount);
    }
    else{
        cout << "Withdrawal amount must be greater than 0 "
                << "Operation canceled\n";    
    }
    reset(initi, preci);
}

format setForm(){
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void reset(format f, precizie p){
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}