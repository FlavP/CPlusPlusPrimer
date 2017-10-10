/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tvmain.cpp
 * Author: flavius
 *
 * Created on October 10, 2017, 2:19 PM
 */

#include <iostream>
#include "ch15tv.h"

using namespace std;

/*
 * 
 */


int main() {
    using std::cout;
    Tv sams;
    cout << "Initial settings for Sam TV:\n";
    sams.settings();
    sams.onoff();
    sams.channup();
    sams.settings();
    
    Remote smart;
    smart.set_chan(sams, 10);
    smart.volup(sams);
    smart.volup(sams);
    sams.settings();
    
    Tv sams2(Tv::On);
    sams2.set_mode();
    smart.set_chan(sams2, 23);
    sams2.settings();
    return 0;
}

