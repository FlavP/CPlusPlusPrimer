/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   exercises.cpp
 * Author: flavius
 *
 * Created on November 6, 2017, 11:52 AM
 */

#include <iostream>
#include <cstdlib>
#include <array>

using namespace std;

/*
 * 
 

Review exercise one, with braces
class Z200{
private:
    int j;
    char ch;
    double z;
public:
    Z200(int jv, char chv, zv) : j(jv), ch(chv), z(zv){}
};

double x {8.8}; // or = {8.8}
std::string s {"What a bracing effect!"};
int k {99};
Z200 zip{200, 'Z', 0.67};
std::vector<int> ai {3, 9, 4, 7, 1};

template<class T>
void show2(double x, T fp) {cout << x << " -> " << fp(x) << '\n';}
double f1(double x) {return 1.8*x + 32;}

int main() {
    //show2(18.0, f1);
    show2(18.0, [](double x) {return 1.8 * x + 32;});
    return 0;
}
*/

const int Size = 5; 
template<typename T>

void sum(array<double, Size> a, T fp);

class Adder{
    double tot;
public:
    Adder(double q = 0) : tot(q){}
    void operator()(double w) {tot += w;}
    double tot_v() const {return tot;};
};

int main(){
    double total = 0.0;
    Adder ad(total);
    array<double, Size> temp_c = {32.1, 34.3, 37.8, 35.2, 34.7};
    //sum(temp_c, ad);
    sum(temp_c, [&total](double x){total += x;});
    //total = ad.tot_v();
    cout << "total: " << total << '\n';
    return 0;
}

template<typename T>
void sum(array<double, Size> a, T fp){
    for(auto pt = a.begin(); pt != a.end(); pt++){
        fp(*pt);
    }
}
