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
    char filename[10];
    ifstream infile;    
    filename = "lgi.txt";
    infile.open(filename);
    return 0;
}