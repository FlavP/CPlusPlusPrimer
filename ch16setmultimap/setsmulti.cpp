/* 
 * File:   setsmulti.cpp
 * Author: flavius
 *
 * Created on October 20, 2017, 6:44 AM
 */

#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>
#include <map>
#include <string>
#include <list>

using namespace std;

/*
 * 
 */

template<class T>
class TooMuch{
private:
    T val;
public:
    TooMuch(const T & x) : val(x){}
    bool operator()(const T & w){return w > val;}            
};

void outint(int i) {cout << i << " ";}

void ShowMe(double d);

int main() {
    /*
    const int N = 6;
    string s1[N] = {"buffon", "thinkers", "for", "heavy", "can", "for"};
    string s2[N] = {"metal", "any", "food", "elegant", "deliver", "for"};
    set<string> A(s1, s1 + N);
    set<string> B(s2, s2 + N);
    ostream_iterator<string, char> out(cout, " ");
    cout << "Set A: ";
    copy(A.begin(), A.end(), out);
    cout << endl;
    
    cout << "Set B: ";
    copy(B.begin(), B.end(), out);
    cout << endl;
    
    cout << "Intersection of A and B: \n";
    set_intersection(A.begin(), A.begin(), B.begin(), B.end(), out);
    cout << endl;    
    
    cout << "Union of A and B: ";
    set_union(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;
    
    cout << "A different from B: ";
    set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;
    
    set<string> C;
    cout << "Set C: ";
    set_union(A.begin(), A.end(), B.begin(), B.end(),
            insert_iterator<set<string> > (C, C.begin()));
    copy(C.begin(), C.end(), out);
    cout << endl;
    
    string s3("grumpy");
    C.insert(s3);
    cout << "C after the s3 insertion: ";
    copy(C.begin(), C.end(), out);
    cout << endl;
    
    cout << "Showing a range: ";
    copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);

    typedef int KeyType;
    typedef pair<const KeyType, string> Pair;
    typedef multimap<KeyType, string> MapCode;
    MapCode codes;
    
    codes.insert(Pair(415, "San Francisco"));
    codes.insert(Pair(510, "Oakland"));
    codes.insert(Pair(718, "Brooklyn"));
    codes.insert(Pair(718, "Staten Island"));
    codes.insert(Pair(415, "San Rafael"));
    codes.insert(Pair(510, "Berkeley"));
    
    cout << "Number of cities with area code 415:\n";
    cout << codes.count(415) << endl;
    
    cout << "Number of cities with area code 718:\n";
    cout << codes.count(718) << endl;
    
    cout << "Number of cities with area code 510:\n";
    cout << codes.count(510) << endl;
    
    MapCode::iterator iter;
    for(iter = codes.begin(); iter != codes.end(); ++iter)
        cout << "     " << (*iter).first << ",  " << (*iter).second << endl;
    
    pair<MapCode::iterator, MapCode::iterator> range = codes.equal_range(718);
    cout << "Cities with area code 718:\n";
    for(iter = range.first; iter != range.second; ++iter)
        cout << (*iter).second << endl;
     
    list<int> una = {200, 400, 300, 500, 900};
    for_each(una.begin(), una.end(), outint);
    TooMuch<int> iin(500);
    una.remove_if(iin);
    cout << endl;
    for_each(una.begin(), una.end(), outint);
     */
    const int LIM = 6;
    double arr1[LIM] = {28, 29, 30, 35, 38, 59};
    double arr2[LIM] = {63, 65, 69, 75, 80, 99};
    vector<double> gr8(arr1, arr1 + LIM);
    vector<double> m8(arr2, arr2 + LIM);
    cout.setf(ios_base::fixed);
    cout.precision(1);
    cout << "gr8\t";
    for_each(gr8.begin(), gr8.end(), ShowMe);
    cout << endl;
    cout << "m8\t";
    for_each(m8.begin(), m8.end(), ShowMe);
    cout << endl;
    
    vector<double> sum(LIM);
    transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(), 
            plus<double>());
    cout << "sum:\t";
    for_each(sum.begin(), sum.end(), ShowMe);
    cout << endl;
    
    vector<double> product(LIM);
    transform(gr8.begin(), gr8.end(), product.begin(), 
            bind1st(multiplies<double>(), 2.5));
    cout << "prod:\t";
    for_each(product.begin(), product.end(), ShowMe);
    cout << endl;
    return 0;
}

void ShowMe(double d){
    cout.width(6);
    cout << d << ' ';
}
