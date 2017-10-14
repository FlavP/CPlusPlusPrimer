/* 
 * File:   magic.cpp
 * Author: flavius
 *
 * Created on October 14, 2017, 1:03 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

/*
 * 
 */

class Grand{
private:
    int hold;
public:
    Grand(int h = 0) : hold(h){}
    virtual void Speak() const {cout << "I am a grand class!\n";}
    virtual int Value() const {return hold;}
};

class Superb : public Grand{
public:
    Superb(int h = 0) : Grand(h){}
    void Speak() const {cout << "I am a superb class";}
    virtual void Say() const {
        cout << "I hold the superb value of " << Value() << "!\n";
    }
};

class Magneficent : public Superb{
private:
    char ch;
public:
    Magneficent(int h = 0, char c = 'A') : Superb(h), ch(c) {}
    void Speak() const {cout << "I am a magneficent class!!\n";}
    void Say() const {cout << "I hold the character " << ch <<
            " and the integer " << Value() << "!\n";}
};

Grand * Lets();
int main() {
    srand(time(0));
    Grand * pg;
    Superb * ps;
    for(int i = 0; i < 5; i++){
        pg = Lets();
        pg->Speak();
        if(ps = dynamic_cast<Superb *>(pg)){
            ps->Say();
        }
    }
    return 0;
}

Grand * Lets(){
    Grand * p;
    switch(rand() % 3){
        case 0: p = new Grand(rand() % 100);
                 break;
        case 1: p = new Superb(rand() % 100);
                 break;
        case 2: p = new Magneficent(rand() % 100, 'A' + rand() % 26);
                break;
    }
    return p;
}

