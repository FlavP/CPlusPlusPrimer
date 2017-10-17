/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   workermain.cpp
 * Author: flavius
 *
 * Created on October 17, 2017, 2:06 PM
 */

#include <iostream>
#include <cstring>
#include "worker.h"

using namespace std;

/*
 * 
 */
const int SIZE = 5;
int main() {
    Worker * lolas[SIZE];
    int ct;
    for(ct = 0; ct < SIZE; ct++){
        char choice;
        cout << "Enter the employee category:\n"
                << "w: waiter s: singer   "
                << "t: singing waiter  q: quit\n";
        cin >> choice;
        while(strchr("wstq", choice) == NULL){
            cout << "Please enter a, w, s, t, or q: ";
            cin >> choice;
        }
        if(choice == 'q')
            break;
        switch(choice){
            case 'w': lolas[ct] = new Waiter;
            break;
            case 's': lolas[ct] = new Singer;
            break;
            case 't': lolas[ct] = new SingingWaiter;
            break;
        }
        cin.get();
        lolas[ct]->Set();
    }
    int i;
    for(i = 0; i < ct; i++){
        cout << endl;
        lolas[i]->Show();
    }
    for(i = 0; i < ct; i++)
        delete lolas[i];
    cout << "Bye.\n";
    return 0;
}

