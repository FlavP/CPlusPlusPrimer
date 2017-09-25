/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "list.h"

List::List(){
    lastItem = 0;
    std::cout << "Empty list initialized\n";
}

bool List::listempty() const{
    return lastItem == 0;
}

bool List::listfull() const{
    return lastItem == NoItems;
}

bool List::additem(const Item& it){
    if(lastItem < NoItems){
        members[lastItem++] = it;
        return true;
    }
    else
        return false;
}

void List::visit(void(*pf)(Item&)){
    int i;
    for(i = 0; i < lastItem; i++){
        pf(members[i]);
    }
 }
