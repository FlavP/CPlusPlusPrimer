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
#include <string>
#include "brass.h"

using namespace std;

/*
 * 
 */

const int CLIENTS = 4;

int main() {
    /*
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
    */
    using std::cin;
    using std::cout;
    using std::endl;
    Brass * clients[CLIENTS];
    std::string temp;
    long tempval;
    double balance;
    char type;
    for(int i=0; i < CLIENTS; i++){
        cout << "Enter client's name: ";
        getline(cin, temp);
        cout << "Account number: ";
        cin >> tempval;
        cout << "Balance: ";
        cin >> balance;        
        cout << "Type of account (1 for regular, 2 for plus): ";
        while(cin >> type && (type != '1' && type != '2')){
            cout << "1 or 2 please: ";            
        }
        if(type == '1'){
            clients[i] = new Brass(temp, tempval, balance);
        }else{
            double tempmax, temprate;
            cout << "Enter the maximum debt: ";
            cin >> tempmax;
            cout << "Enter the interest rate: ";
            cin >> temprate;
            clients[i] = new BrassPlus(temp, tempval, balance,
                    tempmax, temprate);
        }
        while(cin.get() != '\n')
            continue;
    }
    cout << endl;
    for(int i=0; i < CLIENTS; i++){
        clients[i]->ViewAccount();
        cout << endl;
    }
    for(int i=0; i < CLIENTS; i++){
        delete clients[i];
    }
    return 0;
}

