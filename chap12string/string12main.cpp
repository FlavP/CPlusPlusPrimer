/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   string12main.cpp
 * Author: flavius
 *
 * Created on September 26, 2017, 12:25 PM
 */
#include <iostream>
#include "string12.h"

using namespace std;

/*
 * 
 */
const int ArSize = 10;
const int CINLEN = 81;
int main() {
    String12 name;
    String12 quotes[ArSize];
    cout << "Enter your name \n";
    cin >> name;
    cout << name << ", enter a quote having no more than " << ArSize 
            << " characters <empty line to quit>:\n";
    char temp[CINLEN];
    int i;
    for(i = 0; i < ArSize; i++){
        cout << i + 1 << ": ";
        cin.get(temp, CINLEN);
        while(cin.get() && cin.get() != '\n')
            continue;
        if(!cin || temp[0] == '\0')
            break;
        else
            quotes[i] = temp;
    }
    int total = i;
    if(total > 0){
        cout << "Here are your quotes: \n";
        for(i = 0; i < total; i++){
            cout << quotes[i][0] << ": " << quotes[i];
        }
        int shorty = 0;
        int first = 0;
        for(i = 0; i < total; i++){
            if(quotes[i].length() < quotes[shorty].length())
                shorty = i;
            if(quotes[i] < quotes[first])
                first = i;
        }
    cout << "Shortest quote: " << quotes[shorty] << endl;
    cout << "First alphabetically: " << quotes[first] << endl;  
    cout << "The program used: " << String12::LengthOf()
            << " string objects" <<endl;
    }
    else
        cout << "No input, bye!\n";
    return 0;
}

