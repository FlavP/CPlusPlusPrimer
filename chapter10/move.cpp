/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "move.h"

Move::Move(double a, double b){
    x = a;
    y = b;
}

void Move::showmove(){
    std::cout << "X = " << x << std::endl;
    std::cout << "Y = " << y << std::endl;
}

Move Move::add(const Move& m) const{
    Move gigel;
    gigel.x = m.x + this->x;
    gigel.y = m.y + this->y;
    return gigel;
}

void Move::reset(double a, double b){
    x = a;
    y = b;
}