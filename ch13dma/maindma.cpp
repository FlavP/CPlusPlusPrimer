/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   maindma.cpp
 * Author: flavius
 *
 * Created on October 4, 2017, 12:50 PM
 */

#include <iostream>
#include "ch13dma.h"

using namespace std;

/*
 * 
 */
int main() {
    using std::cout;
    using std::endl;
    baseDMA shirt("Portable", 8);
    lacksDMA balloon("red", "Fluppo", 4);
    hasDMA map("Mercator", "Chicago Red Socks", 5);
    cout << "Displaying base object: " << endl;
    cout << shirt << endl;
    cout << "Displaying lacking object: " << endl;
    cout << balloon << endl;
    cout << "Displaying having object: " << endl;
    cout << map << endl;    
    lacksDMA balloon2(balloon);
    cout << "Result of lacksDMA copy:\n";
    cout << balloon2 << endl;
    hasDMA map2;
    map2 = map;
    cout << "Result of hasDMA assignment:\n";
    cout << map2 << endl;
    return 0;
}

