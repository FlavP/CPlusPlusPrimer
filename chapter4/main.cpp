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
    //the last character of every string is the null character '\0'
    //char bird[11] = "Mr. Cheeps";
    //char fish[] = "Bubbles";
    //int arr_size = 20;
    //char arr_name[arr_size];
    //cin.getline(ar_name, arr_size) -> reads arr_size characters or until it
    //encounters '\n' (new line), so it reads an entire line
    //it does not save the new line
    //also cin.get(), which is a variaton of getline, but it does not
    //discard the new line, which can be tricky, if you have more cin.get()
    //statements, so you can use a cin.get() to get rid of new lines
    //cin.get(arr_name, arr_size).get();
    //cin.clear() -> gets rid of empty lines
    //string -> you can initialize a string, concatenate with '+'
    //assing a string with another str1 = str2 -> valid
    //instead of cin.getline(char_array, 20) you have getline(cin, string)
    peshte * stiuca = new peshte;
    strcpy(stiuca->kind, "stiuca");
    stiuca->lenght = 15;
    stiuca->size = 10;
    cout << stiuca->kind << endl;
    
    return 0;
}

