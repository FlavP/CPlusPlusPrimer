/* 
 * File:   operations.cpp
 * Author: flavius
 *
 * Created on October 21, 2017, 8:25 PM
 */

#include <algorithm>
#include <valarray>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

/*
 * Operations with valarray
 
int main() {
    vector<double> data;
    double temp;
    cout << "Enter numbers, (<= 0 to quit):\n";
    while(cin >> temp && temp > 0)
        data.push_back(temp);
    sort(data.begin(), data.end());
    int size = data.size();
    valarray<double> numbers(size);
    int i;
    for(int i = 0; i < size; i++)
        numbers[i] = data[i];
    valarray<double> calcul(size);
    calcul = numbers + 2.0 * sqrt(numbers);
    cout.setf(ios_base::fixed);
    cout.precision(4);
    for(i = 0; i < size; i++){
        cout.width(8);
        cout << numbers[i] << ": ";
        cout.width(8);
        cout << calcul[i] << endl;
    }
    return 0;
}
 

//Operations with slice
    const int SIZE = 12;
    typedef valarray<int> vint;
    void show(const vint & v, int cols);
    
int main(){
    vint twlv(SIZE);
    int i;
    for(i = 0; i < SIZE; ++i)
        twlv[i] = rand() % 10;
    cout << "\nOriginal array:\n";
    show(twlv, 3);
    vint coll(twlv[slice(1, 4, 3)]);
    cout << "\nSecond column:\n";
    show(coll, 1);
    vint rowl(twlv[slice(3, 3, 1)]);
    cout << "\nSecond row:\n";
    show(rowl, 3);
    twlv[slice(2,4,3)] = 10;
    cout << "\nAssigned the las column to 10:\n";
    show(twlv, 3);
    twlv[slice(0,4,3)] = vint(twlv[slice(1,4,3)]) + 
            vint(twlv[slice(2,4,3)]);
    cout << "\nSet the first column the sum of the las two:\n";
    show(twlv, 3);
    return 0;
}

void show(const vint & v, int cols){
    int lim = v.size();
    int i;
    for(i = 0; i < lim; i++){
        cout.width(3);
        cout << v[i];
        if((i + 1) % cols == 0)
            cout << endl;
        else
            cout << ' ';
    }
}
*/

//Try a palindrome

void toLower(string & st);

int main(){
    string s1;
    string s2;
    cout << "Enter a string:\n";
    getline(cin, s1);
    int size = s1.size();
    int i;
    for(i = 0; i < size; i++){
        s2.push_back(s1[size - 1 - i]);
    }
    
    toLower(s1);
    toLower(s2);
    cout << "String s1 is: " << s1 << endl;
    cout << "String s2 is: " << s2 << endl;
    if(s1 == s2)
        cout << "It's a palindrome!!!";
    else
        cout << "Not quite";
    return 0;
}

void toLower(string & st){
    int i;
    for(i = 0; i < st.size(); i++){
        st[i] = tolower(st[i]);
        if(ispunct(st[i]) || isspace(st[i]))
            st.erase(st.begin() + i);
    }
}