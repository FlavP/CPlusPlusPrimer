/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   usestock.cpp
 * Author: flavius
 *
 * Created on July 5, 2017, 7:09 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "stock10.h"
#include "bank.h"
#include "stack.h"
#include "sales.h"
#include "move.h"

using namespace std;

/*
 * 
 */
const int STK = 4;
int main() {
    { // extra {} for displaying the message after destructor is called
    using std::cout;
    cout << "Using constructors to create new objects\n";
    /*
    Stock stock1("Nanosmart", 12, 20.0);
    stock1.show();
    Stock stock2 = Stock("Boffo Objects", 2, 2.0);
    stock2.show();
    cout << "Asigning stock1 to stock2:\n";
    stock2 = stock1;
    cout << "Listing stock1 and stock2:\n";
    stock1.show();
    stock2.show();
    cout << "Using a constructor to reset an object\n";
    stock1 = Stock("Nifty Foods", 10, 50.0); //temp object
    cout << "Revised object:\n";
    stock1.show();
    cout << "Done\n";
    Stock topval = stock1.topvall(stock2);
    cout << "Top valoarea este: " << endl;
    topval.show();
    cout << endl;
    
    Stock sticks[STK] = {
        Stock("Nanosmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprise", 60, 6.5)
    };
    const Stock *topvalue = &sticks[0];
    int i;
    for(i = 1; i < STK; i++){
        topvalue = &topvalue->topvall(sticks[i]);
    }
    cout << "Valoarea de top este: " << endl;
    topvalue->show();
    
    BankAccount bob("Bob Bobici", "ROING224455", 5000.42);
    bob.showAccount();
    bob.deposit(200);
    bob.showAccount();
    bob.withdraw(1200);
    bob.showAccount();
    BankAccount ilinca;
    ilinca.showAccount();
    
    Stack st;
    char ch;
    customer cum;
    cout << "Please enter A to add a customer, P to process or Q to quit: ";
    while(cin >> ch && toupper(ch) != 'Q'){
        while(cin.get() != '\n')
            continue;
        if(!isalpha(ch)){
            cout << '\a';
            continue;
        }
        switch(ch){
        case 'A':
        case 'a':            
            cout << "Enter the full name: \n";
            cin.getline(cum.fullname, 35);
            cout << "Enter the sum: \n";
            cin >> cum.payment;
            if(st.is_full())
                cout << "Stack already full";
            else{
            st.add_customer(cum);
            }
            break;
        case 'P':
        case 'p':
            if(st.is_empty())
                cout << "Stack is empty";
            else{
                st.rem_customer(cum);
                cout << "Customer " << cum.fullname << " has been processed \n";
            }
            break;
        } 
        cout << "Please enter A to add a customer, P to process or Q to quit: ";        
     }
    
    double arr[6] = {-12.2, -10.4, 5.7, 3.14, -3.0, 2.1};
    Sales sl1(arr, 6);
    sl1.showSales();
    */
    Move a(1.0, 2.0);
    Move b(3.0, 4.0);
    Move c;
    a.showmove();
    c = a.add(b);
    c.showmove();
    a.reset(3.0, 3.0);
    a.showmove();
    }
    cout << "Bye!";
    return 0;
}

