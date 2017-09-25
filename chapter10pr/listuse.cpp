/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   listuse.cpp
 * Author: flavius
 *
 * Created on September 25, 2017, 12:32 PM
 */

#include <cstdlib>
#include <iostream>
#include "list.h"

using namespace std;

/*
 * 
 */

void showItem(Item & i);

int main() {
    List gheo;
    void (*pf)(Item & i);
    pf = &showItem;
    unsigned long ter;
    while(!gheo.listfull()){
        cout << "Introduceti elemente sau 0 pentru quit\n";
        cin >> ter;
        if(ter == 0)
                break;
        else{            
            gheo.additem(ter);            
        }
    }
    gheo.visit(pf);
    return 0;
}

void showItem(Item & i){
    std::cout << "The item is: " << i << std::endl;
}