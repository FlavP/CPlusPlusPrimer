/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   abcmain.cpp
 * Author: flavius
 *
 * Created on October 6, 2017, 1:47 PM
 */

#include <iostream>
#include <string>
#include "abcsource.h"

using namespace std;

/*
 * 
 */
int main() {
    BaseDMA b1("Ionel", "Ionelule", "Eu stau degeaba");
    //b1.ShowDMA();
    AbcDMA *a1;
    a1 = &b1;
    a1->ShowDMA();
    return 0;
}

