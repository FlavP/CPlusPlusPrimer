/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: flavius
 *
 * Created on July 3, 2017, 12:54 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <locale>
#include <cstring>

using namespace std;

/*2b
 * 

string quote(string str1, string str2);
string quote(int x, string str);
string quote(double x, string str2);

int main() {
    int x = 100;
    double y = 20019.31;
    string c = "Azi plec";
    string str = "\"";
    cout << quote(x, str) << endl;
    cout << quote(y, str) << endl;
    cout << quote(c, str) << endl;
    return 0;
}

string quote(string str1, string str2){
    string final;
    final = str2 + str1 + str2;
    return final;
}

string quote(int str1, string str2){
    string final;
    final = str2 + to_string(str1) + str2;
    return final;
}

string quote(double str1, string str2){
    string final;
    final = str2 + to_string(str1) + str2;
    return final;
}
 

struct box{
    char maker[40];
    float height;
    float weight;
    float width;
    float volume;
};

void display_box(const box &bo);

void set_volume(box &bo);

int main(){
    box bibi = {"Ion Popescu", 2, 2, 2};
    display_box(bibi);
    set_volume(bibi);
    display_box(bibi);
    return 0;
}

void display_box(const box &bo){
    cout << "Name: " << bo.maker << endl;
    cout << "Height: " << bo.height << endl;
    cout << "Weight: " << bo.weight << endl;
    cout << "Width: " << bo.width << endl;
    cout << "Volume: " << bo.volume << endl;
}

void set_volume(box &bo){
    bo.volume = bo.height * bo.weight * bo.width;
}


struct box{
    char maker[40];
    float height;
    float weight;
    float width;
    float volume;
};

template<typename T>
T larger(T a, T b);

template <> box larger<box> (box a, box b);

int main(){
    int a = 40;
    int b = 20;
    box bibi = {"Ion Popescu", 2, 2, 2, 8};
    box titi = {"John Pop", 3, 3, 3, 9};
    char c = 'd';
    char d = 'x';
    float x = 315.01;
    float y = 315.02;
    box *tur = larger(&bibi, &titi);
    cout << larger(a, b) << " is largest between " << a << " and " << b << endl;
    cout << larger(c, d) << " is largest between " << c << " and " << d << endl;
    cout << larger(x, y) << " is largest between " << x << " and " << y << endl;
    cout << tur->volume << " is largest between " << bibi.maker 
            << " and " << titi.maker << endl;
    return 0;
}

template <typename T>
T larger(T a, T b){
    return a > b ? a : b;
}

template <> box larger<box> (box a, box b){    
    return a.volume > b.volume ? a : b;
}


void print_string(string str, int n=1);

int main(){
    string unstr = "Ana are mere";
    print_string(unstr, 4);
    unstr = "Ana are pere";
    print_string(unstr);
    return 0;
}

void print_string(string str, int n){
    int i = 0;
    //cout << str << endl;
    while(i++ < n){
        cout << str << endl;
    }
}


struct CandyBar{
    char *brand;
    double weight;
    int cals;
};

void create_candy(CandyBar &candy, char *brand = "Brandy Bunch", 
        double weight = 2.85, int cals = 385);
void display_candy(const CandyBar &candy);

int main(){
    CandyBar uchi;
    create_candy(uchi);
    display_candy(uchi);
    return 0;
}

void create_candy(CandyBar &candy, char *brand ,double weight, int cals){
    candy.brand = brand; // Big news alert
    candy.weight = weight;
    candy.cals = cals;
}

void display_candy(const CandyBar &candy){
    cout << candy.brand << endl;
    cout << candy.weight << endl;
    cout << candy.cals << endl;
}


void changestr(string &str);

int main(){
    string str;
    string &altst = str;
    cout << "Please enter a string" << endl;
    getline(cin, str);
    while(str != "q"){
        changestr(altst);
        cout << str << endl;
        cout << "Please enter another string" << endl;
        getline(cin, str);
    }
    cout << "Done!" << endl;
}

void changestr(string &str){
    string temp;
    for(int i=0; i < str.length(); i++){
        temp += toupper(str[i]);
    }
    str = temp;
}


struct stringy{
    char *str;
    int ct;
};

void set(stringy &str, char *clet);

void show(const char *ch, int times=1);

void show(const stringy &str, int times=1);

int main(){
    stringy beany;
    char testing[] = "Reality is real.";
    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");    
    return 0;
}

void set(stringy &str, char *chlet){
    str.ct = strlen(chlet);
    str.str = new char[str.ct];
    strcpy(str.str, chlet);    
}

void show(const char *ch, int times){
    int i = 0;
    while(i++ < times){
        cout << ch << endl;
    }
}

void show(const stringy &str, int times){
    int i = 0;
    while(i++ < times){
        cout << str.str << endl;
    }
}
*/

template <typename T>
T retmax(T arr[], int n);

template <> char * retmax <char *> (char *[], int n);

int main(){
    int intSize = 4;
    int doubleSize = 6;
    int charSize = 5;
    char str1[] = "unu";
    char str2[] = "unuu";
    char str3[] = "unuuu";
    char str4[] = "unuu";
    char str5[] = "unuuu";
    char *charr[charSize] = {str1, str2, str3, str4, str5};
    int arr[intSize] = {110, 219, 342, 432};
    double brarr[doubleSize] = {205.3, 204.8, 208.0, 208.01, 207.9, 199.2};
    cout << "Integ max = " << retmax(arr, intSize) << endl;
    cout << "Double max = " << retmax(brarr, doubleSize) << endl;
    cout << "Char max = " << retmax(charr, charSize) << endl; // Il apelezi
    //nepointat, NU retmax(*charr, charSize), nici retmax(*charr[], charSize)
    return 0;
}

template <typename T>
T retmax(T arr[], int n){
    T maxim = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > maxim)
            maxim = arr[i];
    }
    return maxim;
}

template <>
char * retmax(char *charr[], int n){
    //cout << "Ceva putred" << endl;
    char * maxim = charr[0];
    for(int i = 0; i < n; i++){
        if(strlen(maxim) < strlen(charr[i]))
            maxim = charr[i];
    }
    return maxim;
}