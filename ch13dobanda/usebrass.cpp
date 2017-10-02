/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   usebrass.cpp
 * Author: flavius
 *
 * Created on October 2, 2017, 2:12 PM
 */

#include <iostream>
#include "brass.h"

using namespace std;

/*
 * 
 */
int main() {
    using std::cout;
    using std::endl;
    
    Brass Piggy("Piggy Pie", 381299, 4000.00);
    BrassPlus Hogus("Pigface Prick", 3822882, 3000.00);
    Piggy.ViewAccount();
    cout << endl;
    Hogus.ViewAccount();
    cout << endl;
    Hogus.Deposit(1000.00);
    cout << "Hogus new balance" << Hogus.Balance() << endl;
    Piggy.Withdraw(4200.00);
    cout << "Piggy's new balance" << Piggy.Balance() << endl;
    Hogus.Withdraw(4200.00);
    Hogus.ViewAccount();
    return 0;
}

