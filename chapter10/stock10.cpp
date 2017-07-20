/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <c++/4.8/bits/ios_base.h>
#include "stock10.h"

//constructors (verbose version)

Stock::Stock(){
    std::cout << "Default constructor called" << std::endl;
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const std::string& co, long n, double pr){
    std::cout << "Constructor using " << co << " called\n";
    company = co;
    
    if(n < 0){
        std::cout << "Number of shares can't be negative"
                << company << " shares set to 0" << std::endl;
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_total();
}

//class destructor
Stock::~Stock(){
    std::cout << "Bye, " << company << "!\n";
} //verbose class destructor

//other methods

void Stock::buy(long num, double price){
    if(num < 0){
        std::cout << "Number of shares purchased can't be negative. "
                << "Transaction aborted.\n";
    }
    else{
        shares += num;
        share_val = price;
        set_total();
    }
}

void Stock::sell(long num, double price){
    using std::cout;
    if(num < 0){
        cout << "Number of shares sold can't be negative. "
                << "Transaction aborted.\n";
    }
    else if(num > shares){
        cout << "You can't sell more than you have! "
                << "Transaction aborted.\n";
    }
    else{
        shares -= num;
        share_val = price;
        set_total();
    }
}

void Stock::update(double price){
    share_val = price;
    set_total();
}

void Stock::show() const{
    using std::cout;
    using std::ios_base;
    //set format to #.###
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
    cout << "Company: " << company
         << " Shares: " << '\n';
    cout << " Share Price: $" << share_val;
    //set format to #.##
    cout.precision(2);
    cout << " Total Worth: $" << total_val << '\n';
    //restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

const Stock & Stock::topvall(const Stock & s) const{
    if(s.total_val > total_val)
        return s;
    else
        return *this;
}
