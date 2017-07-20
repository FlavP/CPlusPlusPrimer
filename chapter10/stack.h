/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stack.h
 * Author: flavius
 *
 * Created on July 6, 2017, 4:42 PM
 */

#ifndef STACK_H
#define STACK_H
struct customer{
        char fullname[35];
        double payment;
    };
    typedef customer Item;
class Stack{
private:    
    static const int SD = 5;
    Item items[SD];
    int top;
public:
    Stack(){ top = 0;};
    bool is_full();
    bool is_empty();
    bool add_customer(const Item &);
    bool rem_customer(const Item &);
};


#endif /* STACK_H */

