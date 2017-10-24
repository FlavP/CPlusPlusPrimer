/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   starting.cpp
 * Author: flavius
 *
 * Created on October 24, 2017, 2:47 PM
 */

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <istream>
#include <ostream>

using namespace std;

/*
 * 
 /

const int LIM = 20;

int main(){
    char ch[LIM];
    char cts;
    cout << "Enter characters:\n";
    cin.get(ch, LIM, '$');
    cin.get(cts);
    cout << ch << endl;
    cout << "And the last character is: " << cts << endl;
    
    return 0;
}

*/

int main(){
    const char * filename;
    ofstream outfile; 
    char ch;
    filename = "lgi.txt";
    outfile.open(filename);
    if(!outfile.is_open()){
        cout << "Could not open the file: " << filename << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Gimme output: ";
    while(cin.get(ch)){
        if(outfile.eof())
            break;
        outfile << ch;    
    }
    outfile.close();    
    char input;
    ifstream infile;
    infile.open(filename);
    cout << "\nWe are reading the file now: \n";
    if(infile.is_open()){
        while(infile.get(input))
                cout << input;
    }
    return 0;
}