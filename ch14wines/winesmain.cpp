/* 
 * File:   winesmain.cpp
 * Author: flavius
 *
 * Created on October 15, 2017, 8:58 PM
 */

#include <iostream>
#include <valarray>

#include "wines.h"

using namespace std;

/*
 * 
 */
int main() {
    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};
    valarray <int> abla(b, YRS);
    valarray <int> blabla;
    Wine w1("Ciocothe locco", YRS, y, b);
    w1.show();
    return 0;
}

