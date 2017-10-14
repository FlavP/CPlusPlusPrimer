/* 
 * File:   usesales.cpp
 * Author: flavius
 *
 * Created on October 14, 2017, 9:30 AM
 */

#include <iostream>
#include "sales.h"

using namespace std;

/*
 * 
 */
int main() {
    double vals1[12] = {
    1220, 1100, 1122, 2212, 1232, 2334,
    2884, 2393, 3302, 2992, 3002, 3544
    };
    double vals2[12] = {
    12, 11, 22, 21, 32, 34,
    28, 29, 33, 29, 32, 35
    };
    Sales sales(2011, vals1, 12);
    LabeledSales sales2("Blogstar", 2012, vals2, 12);
    
    cout << "First try\n";
    try{
        int i;
        cout << "Year = " << sales.ret_year() << endl;
        for(i = 0; i < 12; ++i){
            cout << sales[i] << ' ';
            if(i % 6 == 5)
                cout << endl;
        }
        cout << "End of first try\n";
    }
    catch(LabeledSales::nbad_index & bad){
        cout << bad.what();
        cout << "Company: " << bad.ret_label() << endl;
        cout << "bad index: " << bad.return_bad_index() << endl;
    }
    catch(Sales::bad_index & bad){
        cout << bad.what();
        cout << "bad index" << bad.return_bad_index() << endl;
    }
    cout << "\nNext try:\n";
    try{
        sales2[2] = 37.5;
        sales[20] = 23345;
        cout << "End of second try\n";
    }
    catch(LabeledSales::nbad_index & bad){
        cout << bad.what();
        cout << bad.ret_label() << endl;
        cout << bad.return_bad_index() << endl;
    }
    catch(Sales::bad_index & bad){
        cout << bad.what();
        cout << bad.return_bad_index() << endl;
    }
    return 0;
}

