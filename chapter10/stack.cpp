/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "stack.h"

bool Stack::is_full(){
    if(top > SD)
        return true;
    else
        return false;
}

bool Stack::is_empty(){
    if(top == 0)
        return true;
    else
        return false;
}

bool Stack::add_customer(const Item & item){
    if(top < SD){
        items[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::rem_customer(const Item & item){
    if(top > 0){
        items[top--] = item;
        return true;
    }
    else
        return false;
}