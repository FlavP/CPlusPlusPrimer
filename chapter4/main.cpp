/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: flavius
 *
 * Created on September 15, 2017, 4:30 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

/*
 * 
 */

struct peshte{
    char kind[10];
    int size;
    int lenght;
};

//Read question 14 answer on page 1338, iti is really interesting

int main() {
    char suca[20];
    string waldo;
    double ted = 10000.1324;
    double *cioc = &ted;
    float triacle[10];
    float * prr = triacle;
    int sizel;
    int * arr;
    strcpy(suca, "cheeseburger");
    //suca = "cheeseburger";
    cout << suca << endl;
    waldo = "Waldorf Salad";
    cout << waldo << endl;
    peshte fishy;
    strcpy(fishy.kind, "caras");
    fishy.lenght = 10;
    fishy.size = 400;
    *(prr + 9) = 100;
    cout << fishy.kind << endl;
    cout << *cioc << endl;
    cout << triacle[9] << endl;
    /*
    cout << "How big is the array: " << endl;
    cin >> sizel;
    arr = new int[sizel];
    
    for(int i = 0; i < sizel; i++){
        cout << "Elementul " << i + 1 << " are valoarea: " << endl;
        cin >> arr[i];
    }
    for(int i = 0; i < sizel; i++){
        cout << "Elementul " << i + 1 << " are valoarea: " << arr[i] << endl;
    }
     
    vector <int> other(sizel);
    for(int i = 0; i < sizel; i++){
        cout << "Elementul " << i + 1 << " are valoarea: " << endl;
        cin >> other[i];
    }
    for(int i = 0; i < sizel; i++){
        cout << "Elementul " << i + 1 << " are valoarea: " << other[i] << endl;
    }
    */
    peshte * stiuca = new peshte;
    strcpy(stiuca->kind, "stiuca");
    stiuca->lenght = 15;
    stiuca->size = 10;
    cout << stiuca->kind << endl;
    return 0;
}

