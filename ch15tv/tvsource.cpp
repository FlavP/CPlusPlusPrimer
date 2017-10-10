/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "ch15tv.h"

bool Tv::volup(){
    if(volume < MaxVol){
        volume++;
        return true;
    }
    else
        return false;
}

bool Tv::voldown(){
    if(volume > 0){
        volume--;
        return true;
    }
    else
        return false;
}

bool Tv::channup(){
    if(channel < maxchannel)
        channel++;
    else
        channel = maxchannel;
}

bool Tv::chandown(){
    if(channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::settings() const{
    using std::cout;
    using std::endl;
    if(state == On){
        cout << "Volume: " << volume << endl;
        cout << "Channel: " << channel << endl;
        cout << "Mode: " << (mode == Antenna ? "antenna" : "cable") << endl;
        cout << "Input: " << (input == TV ? "TV" : "DVD") << endl;
    }
}