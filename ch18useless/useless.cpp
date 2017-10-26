/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   useless.cpp
 * Author: flavius
 *
 * Created on October 26, 2017, 12:32 PM
 */

#include <iostream>
#include <utility>

using namespace std;

/*
 * 
 */

class Useless{
private:
    int n;                //number of elements
    char *pc;             //pointer to data
    static int ct;        //number of objects
    void ShowObject() const;
public:
    Useless();
    explicit Useless(int k);
    Useless(int k, char ch);
    Useless(const Useless & f); //copy constructor
    Useless(Useless && f);      //move constructor
    ~Useless();
    Useless & operator=(Useless &f);
    Useless & operator=(Useless &&f);
    Useless operator+(const Useless & f) const;
    void ShowData() const;
};

int Useless::ct = 0;

Useless::Useless(){
    ++ct;
    n = 0;
    pc = nullptr;
    cout << "default constructor called; number of objects: " << ct << endl;
    ShowObject();
}

Useless::Useless(int k) : n(k){
    ++ct;
    cout << "int constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    ShowObject();
}

Useless::Useless(int k, char ch) : n(k){
    ++ct;
    cout << "int, char constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    for(int i = 0; i < n ; i++)
        pc[i] = ch;
    ShowObject();
}

Useless::Useless(const Useless& f) : n(f.n){
    ++ct;
    cout << "copy constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    for(int i = 0; i < n ; i++)
        pc[i] = f.pc[i]; 
    ShowObject();
}

Useless::Useless(Useless&& f) : n(f.n) {
    ++ct;
    cout << "Move constructor called; number of objects: " << ct << endl;
    pc = f.pc;  //steal address
    f.pc = nullptr; // give old object nothing in return
    f.n = 0;
    ShowObject();
}

Useless::~Useless(){
    cout << "Destructor called; objects left: " << --ct << endl;
    cout << "deleted object:\n";
    ShowObject();
    delete [] pc;
}

Useless Useless::operator+(const Useless & f) const{
    cout << "Entering operator+()\n";
    Useless temp = Useless(n + f.n);
    for(int i = 0; i < n; i++)
        temp.pc[i] = pc[i];
    for(int i = n; i < temp.n; i++)
        temp.pc[i] = f.pc[i - n];
    cout << "temp object:\n";
    return temp;
}

void Useless::ShowObject() const{
    cout << "Number of elements: " << n;
    cout << "\nData address: " << (void *) pc << endl;
}

void Useless::ShowData() const{
    if(n == 0)
        cout << "Object empty";
    else
        for(int i = 0; i < n; i++)
            cout << pc[i];
    cout << endl;
}

Useless & Useless::operator =(Useless& f){
    if(this == &f)
        return *this;
    delete [] pc;
    n = f.n;
    pc = new char[n];
    for(int i = 0; i < n; i++)
        pc[i] = f.pc[i];
    return *this;
}

Useless & Useless::operator =(Useless&& f){ //move assignement
    if(this == &f)
        return *this;
    delete [] pc;
    n = f.n;
    pc = f.pc;
    f.n = 0;
    f.pc = nullptr;
    return *this;
}

//application

int main() {
    Useless one(10, 'x');
//    Useless two = one;
    Useless two = one + one;      //call copy constructor
//    Useless three(30, 'o');
    Useless three = one;
//    Useless four(one + three); // calls operator+(), move constructor
    Useless four = one + two;
    cout << "Object four: ";
    four.ShowData();    
    cout << "Object one: ";
    one.ShowData();
    cout << "Object two: ";
    two.ShowData();
    cout << "Object three: ";
    three.ShowData();
    four = move(one);
    cout << "Object four: ";
    four.ShowData();
    return 0;
}

