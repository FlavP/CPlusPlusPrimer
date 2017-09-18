/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: flavius
 *
 * Created on June 16, 2017, 6:20 PM
 */
/*
The new operator lets you request memory for a data object while a program is run-
ning.The operator returns the address of the memory it obtains, and you can assign that
address to a pointer.The only means to access that memory is to use the pointer. If the
data object is a simple variable, you can use the dereferencing operator ( *) to indicate a
value. If the data object is an array, you can use the pointer as if it were an array name to
access the elements. If the data object is a structure, you can use the pointer dereferencing
operator (->) to access structure members.
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

struct cars{
    string make;
    int year;
};

/*
 * 
 */
int main() {
    /*
    int ch;
    int count = 0;
    while((ch = cin.get()) != EOF){
        cout.put(char(ch));
        ++count;
    }
    cout << endl << count << " Characters read" << endl;
     
    int arrSize = 100;
    long double factorial[arrSize];
    for(int i = 2; i < arrSize; i++){
	factorial[0] = factorial[1] = 1.0;
	factorial[i] = i * factorial[i-1];
    }
    for(int j = 0; j < arrSize; j++){
	cout << j <<"!= " << factorial[j] << endl;
    }
    
    
    const int noMonths = 4;
    const int noYears = 3;
    int years[noYears] = {2012, 2013, 2014};
    char *months[noMonths] = {"January", "February", "March", "April"};
    int sales[noYears][noMonths];
    int sum = 0;
    for(int i=0; i < noYears; i++){
        for(int j=0; j < noMonths; j++){
            cout << "Sales for " << years[i] << "\t" << months[j] << endl;
            cin >> sales[i][j];
            cout << "Sales for " << years[i] << "\t" << months[j] << "= " << sales[i][j] << endl;
            sum += sales[i][j];
        }
    } 
    cout << "Total sales: " << sum << endl;
     
    int howMany;
    cout << "How many cars" << endl;
    cin >> howMany;
    cars *masini = new cars[howMany];
    for(int i = 0; i < howMany; i++){
        cout << "What type is the car? " << endl;
        cin >> masini[i].make;
        cout << "In what year was it build? " << endl;
        cin >> masini[i].year;
    }
    delete masini;
    
    string a;
    string words[400];
    string word = "done";
    int count = 0;
    int j = 0;
    cout << "Enter the string" << endl;
    getline(cin,a);
    
    for(int i=0; i < a.length(); i++){
         if(a[i] == ' '){
            count++;
            }
         else{
             words[count] += a[i];
          }
         }
    do{
        j++;        
    }while(word.compare(words[j]) != 0 && j <= count);
    cout << "Numarul de cuvinte este " << j << " si al spatiilor " << count << endl;
    
    int sizeMic;
    cout << "How many? " << endl;
    cin >> sizeMic;
    string stars;
    for(int j = sizeMic - 1; j >= 0; j--){
        stars[j] = '*';
        for(int i=0; i < j; i++){
            stars[i] = '-';
        }
        for(int k=0; k < sizeMic; k++){
            cout << stars[k];
        }
        cout << endl;
    }
    cout << "DONE" << endl;
    
    string cela, cola;
    int four, five;
    cout << "Give me a name " << endl;
    getline(cin, cela);
    cout << "Give me a number " << endl;
    cin >> five;
    //cin.clear();
    //cin.sync();
    cin.ignore();
    cout << "Give me another name " << endl;
    getline(cin, cola);
    cout << "Give me another number " << endl;
    cin >> four;
    cout << cela << endl;
    cout << five << endl;   
    cout << cola << endl;
    cout << four << endl; 
    */
    //mai jos e o chestie de notat, cum bagarray de stringuri
    string months[3] = {"January", "February", "March"};
    int years[3] = {2015, 2016, 2017};
    float sales[3][3];
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            cout << "Sales for " << months[i] << " and " << years[j] << " are: ";
            cin >> sales[i][j];
        }
    }
    return 0;
}

