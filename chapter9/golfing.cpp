#include <iostream>
#include <cstring>
#include "golf.h"

using namespace std;

struct chaff{
    char dross[20];
    int slag;
};

int main(){
    /*
    golf ann, andy;
    //setgolf(ann, "Ann Birdfree", 24);
    setgolf(andy);
    showgolf(andy);
    handicap(andy, 22);
    showgolf(andy);
    return 0;
    */
    chaff *unu = new chaff;
    strcpy(unu->dross, "alb");
    unu->slag = 2;
    int buffer[40];
    chaff *doi = new (buffer) chaff;
    strcpy(doi->dross, "negru");
    doi->slag = 5;
    cout << "Slag unu: " << unu->dross << " " << unu->slag << endl;
    cout << "Slag doi: " << doi->dross << " " << doi->slag << endl;
    cout << "Adresa lui buffer: " << &buffer << endl;
    cout << "Adresa lui doi: " << &doi << endl;
}
