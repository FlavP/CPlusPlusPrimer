/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   list.h
 * Author: flavius
 *
 * Created on September 25, 2017, 11:22 AM
 */

#ifndef LIST_H
#define LIST_H

typedef unsigned long Item;

class List{
private:
    enum {NoItems = 10};
    Item members[NoItems];
    int lastItem;
public:
    List();
    bool listempty() const;
    bool listfull() const;
    bool additem(const Item & it);    
    void visit(void(*pf)(Item& item));
};

#endif /* LIST_H */

