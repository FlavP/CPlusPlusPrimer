/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   usearray.cpp
 * Author: flavius
 *
 * Created on October 9, 2017, 12:58 PM
 */

#include <iostream>
#include "array.h"

using namespace std;

/*
 * 
 */
int main(void){
    using std::cout;
    using std::endl;
    ArrayTP<int, 10> sums;
    ArrayTP<double, 10> averages;
    ArrayTP<ArrayTP<int, 5>, 10> combined;
    int i, j;
    for(i = 0; i < 10; i++){
        sums[i] = 0;
        for(j = 0; j < 5; j++){
            combined[i][j] = (i + 1) * (j + 1);
            sums[i] += combined[i][j];
        }
        averages[i] = (double) sums[i] / 10;
    }
    
    for(i = 0; i < 10; i++){
        for(j = 0; j < 5; j++){
            cout.width(2);
            cout << combined[i][j] << ' ';
        }
        cout << ": sum: " << endl;
        cout.width(3);
        cout << sums[i] << " averages: " << averages[i] << endl;
    }
    return 0;
}

