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
#include <cmath>
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
            w1.what();
            w1.err_msg();
            cout << "Not good. Try again\n";
            continue;
        }catch(bad_gmean & w2){
            w2.what();
            cout << w2.err_msg();
            cout << "That's it.\n";
            break;
        }
    }
    return 0;
}

double hmean(double a, double b){
    if(a == -b){
        throw(bad_hmean(a, b));
    }else{
        return 2.0 * a * b/(a + b);
    }
}

double gmean(double a, double b){
    if(a < 0 || b < 0)
        throw(bad_gmean(a, b));
    else
        return std::sqrt(a * b);
}