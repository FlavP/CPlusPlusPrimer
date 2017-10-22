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
#include <set>
#include <iterator>

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
  
int reduce(long ar[], int n);
const int LEN = 11;

int main(){
    long ar[LEN] = {1L, 1L, 2L, 5L, 4L, 5L, 2L, 5L, 5L, 9L, 3L};
    int longit = reduce(ar, LEN);
    cout << "Number of unique sorted elements is: " << longit << endl;
    return 0;
}

int reduce(long ar[], int n){
    set<long> ra(ar, ar + n);
    return ra.size();
}
 
const int LEN = 11;
template<typename T>
int reduce(T ar[], int n);

int main(){
    long ar[LEN] = {1L, 1L, 2L, 5L, 4L, 5L, 2L, 5L, 5L, 9L, 3L};
    string s1[LEN] = {"buffon", "thinkers", "for", "heavy", "can", "for"
    "any", "food", "elegant", "for"};
    int longar = reduce(ar, LEN);
    int longst = reduce(s1, LEN);
    cout << "Number of unique sorted elements in long array is: " 
            << longar << endl;
    cout << "Number of unique sorted elements in string is: " 
            << longst << endl;
    return 0;
}

template<typename T>
int reduce(T ar[], int n){
    set<T> ra(ar, ar + n);
    return ra.size();
}
  

vector<int> Lotto(int hwmny, int winners);

int main(){
    vector<int> winnum = Lotto(51, 6);
    ostream_iterator<int, char> out(cout, " ");
    copy(winnum.begin(), winnum.end(), out);
    return 0;
}

vector<int> Lotto(int hwmny, int winners){
    vector<int> v1;
    int i;
    for(i = 0; i < hwmny; i++)
        v1.push_back(i + 1);
    random_shuffle(v1.begin(), v1.end());
    random_shuffle(v1.begin(), v1.end());
    random_shuffle(v1.begin(), v1.end());
    random_shuffle(v1.begin(), v1.end());
    vector<int> v2;    
    v2 = v1;
    v2.erase(v2.begin() + winners, v2.end());
    return v2;
}

