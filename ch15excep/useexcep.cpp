/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   useexcep.cpp
 * Author: flavius
 *
 * Created on October 11, 2017, 3:54 PM
 */

#include <cstdlib>
#include <iostream>
#include "badharm.h"

using namespace std;

double hmean(double a, double b);
double gmean(double a, double b);

/*
 * 
 */
int main() {
    double x, y, z;
    cout << "Please enter two numbers: ";
    while(cin >> x >> y){
        try{
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << ", " << y 
                    <<"is: " << z << endl;
            z = gmean(x, y);
            cout << "Geometric mean of " << x << ", " << y 
                    <<"is: " << z << endl;
            cout << "Enter additional two numbers or q to <quit>: " << endl;
        }catch(bad_hmean & w1){
            w1.err_msg();
            cout << "Not good.\n";
        }catch(bad_gmean & w2){
            w2.err_msg();
            cout << "Try again.\n";
        }
    }
    return 0;
}

