/* 
 * File:   inpexc.cpp
 * Author: flavius
 *
 * Created on October 22, 2017, 5:59 PM
 */

#include <exception>
#include <iostream>

using namespace std;

/*
 * 
 */
int main() {
    cin.exceptions(ios_base::failbit);
    cout << "Enter numbers: ";
    int sum = 0;
    int input;
    try{
        while(cin >> input){
            sum += input;
        }
    }catch(ios_base::failure & fv){
        cout << fv.what() << endl;
        cout << "Wahaaaa\n";
    }
    cout << "Last value for input: " << input << endl;
    cout << "Last value for sum: " << sum << endl;

    return 0;
}

