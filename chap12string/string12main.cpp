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
#include <ctime>
#include <cstdlib>
#include "string12.h"

using namespace std;

/*
 * 

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
        while(cin && cin.get() != '\n')
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
            cout << quotes[i][0] << ": " << quotes[i] << endl;
        }
        int shorty = 0;
        int first = 0;
        String12 *shortest = &quotes[0];
        String12 *firstone = &quotes[0];
 * 
 * 
 * 
 * 
        for(i = 1; i < total; i++){
            if(quotes[i].length() < shortest->length())
                shortest = &quotes[i];
            if(quotes[i] < *firstone)
                firstone = &quotes[i];
        }
    cout << "Shortest quote: " << *shortest << endl;
    cout << "First alphabetically: " << *firstone << endl;  
    srand(time(0));
    int randi = rand() % total;
    String12 * favo = new String12(quotes[randi]);
    cout << "The program used: " << String12::LengthOf()
            << " string objects" <<endl;
    cout << "My favourite quote is: " << *favo << endl;
    delete favo;
    }
    else
        cout << "No input, bye!\n";
    return 0;
}
 */
        /*for(i = 0; i < total; i++){
            if(quotes[i].length() < quotes[shorty].length())
                shorty = i;
            if(quotes[i] < quotes[first])
                first = i;
        }
         */

int main(){
    String12 s1(" and I am a C++ student");
    String12 s2 = "Please enter your name: ";
    String12 s3;
    cout << s2;
    cin >> s3;
    s2 = "My name is " + s3;
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.stringup();
    cout << "The string\n" << s2 << "\ncontains " << s2.howMany('A')
            << " 'A' characters in it.\n";
    s1 = "red";
    String12 rgb[3] = {String12(s1), String12("green"), String12("blue")};
    cout << "Enter the name of a primary color: ";
    String12 ans;
    bool success = false;
    while(cin >> ans){
        ans.stringlow();
        for(int i = 0; i < 3; i++){
            if(ans == rgb[i]){
                cout << "That is right!\n";
                success = true;
                break;
            }
        }
        if(success)
            break;
        else
            cout << "Try again!\n";
    }
    cout << "Bye\n";
    return 0;
}