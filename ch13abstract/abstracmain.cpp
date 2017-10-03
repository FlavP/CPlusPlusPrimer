/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   abstracmain.cpp
 * Author: flavius
 *
 * Created on October 3, 2017, 2:32 PM
 */

#include <iostream>
#include <string>
#include "accabc.h"

using namespace std;

/*
 * 
 */

const int CLIENTS = 4;

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    AccABC * clients[CLIENTS];
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
            clients[i] = new BrassPlus(temp, tempval, balance, tempmax, temprate);
        }
        while(cin.get() != '\n')
            continue;
    }
    cout << endl;
    for(int i=0; i < CLIENTS; i++){
        clients[i]->showAcc();
        cout << endl;
    }
    for(int i=0; i < CLIENTS; i++){
        delete clients[i];
    }
    return 0;
}
